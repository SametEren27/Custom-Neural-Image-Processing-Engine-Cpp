// include/Tensor.hpp
#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <vector>
#include <iostream>

class Tensor {
public:
    float* data;
    int N, C, H, W; // Batch, Channel, Height, Width
    size_t total_size;

    // NCHW düzeninde bellek tahsisi
    Tensor(int n, int c, int h, int w) : N(n), C(c), H(h), W(w) {
        total_size = (size_t)n * c * h * w;
        data = new float[total_size](); // Sýfýrlarla baþlatýlmýþ heap memory
    }

    // 4D Pointer Aritmetiði
    inline float& at(int n, int c, int h, int w) {
        return data[n * (C * H * W) + c * (H * W) + h * W + w];
    }

    ~Tensor() {
        delete[] data; // Manuel bellek yönetimi
    }
};

#endif