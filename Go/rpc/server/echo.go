package main

import (
	"fmt"
	"net"
	"net/rpc"
)

type EchoService struct {
}

func (p *EchoService) Echo(message string, reply *string) error {
	fmt.Println("client say:", message)
	*reply = "echo server say :" + message
	return nil
}

func main() {
	fmt.Println("waitting or client..")
	rpc.RegisterName("EchoService", new(EchoService))
	listener, err := net.Listen("tcp", ":8888")
	if err != nil {
		panic(err)
	}
	conn, err := listener.Accept()
	if err != nil {
		panic(err)
	}
	rpc.ServeConn(conn)
}
