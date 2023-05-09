#include <iostream>
#include <fstream>
#include "helloworld.pb.h"

int main(int argc, char* argv) {
    // 创建一个 Hello World 消息
    helloworld::helloworld message;
    message.set_id(123);
    message.set_str("Hello, world!");
    message.set_opt(456);

    // 将消息序列化为字节数组
    std::string buffer;
    message.SerializeToString(&buffer);

    // 将序列化后的字节数组写入文件
    std::ofstream output("message.bin", std::ios::binary);
    output.write(buffer.data(), buffer.size());

    // 从文件中读取序列化后的字节数组
    std::ifstream input("message.bin", std::ios::binary);
    std::string input_buffer((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

    // 反序列化消息
    helloworld::helloworld message2;
    message2.ParseFromString(input_buffer);

    // 输出消息内容
    std::cout << "ID: " << message2.id() << std::endl;
    std::cout << "String: " << message2.str() << std::endl;
    std::cout << "Optional: " << message2.opt() << std::endl;

    return 0;
}

