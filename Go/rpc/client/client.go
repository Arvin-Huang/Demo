package main

import (
	"fmt"
	"net/rpc"
)

func main() {
	client, err := rpc.Dial("tcp", "localhost:8888")
	if err != nil {
		panic(err)
	}

	var reply string
	err = client.Call("EchoService.Echo", "Hello world", &reply)
	if err != nil {
		panic(err)
	}
	client.Close()
	fmt.Println(reply)
}
