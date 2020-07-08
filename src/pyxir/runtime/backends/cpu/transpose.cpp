/*
 *  Copyright 2020 Xilinx Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *      http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "pyxir/runtime/runtime.hpp"
#include "transpose.hpp"

namespace pyxir {
namespace runtime {
namespace cpu {

TransposeFunc::TransposeFunc(XLayerHolder &xl)
  : KernelFunc(xl)
{}

void TransposeFunc::operator()(
  std::vector<XBufferHolder> &in_tensors,
  std::vector<XBufferHolder> &out_tensors)
{}

REGISTER_KERNEL_FUNC("cpu.Transpose")
  .set_impl([](XLayerHolder &xl, KernelFuncHolder &kfh) {
    kfh = std::move(KernelFuncHolder(new TransposeFunc(xl)));
  });

} // namespace cpu
} // namespace runtime
} // namespace pyxir
