/*
 * Copyright 2020 OmniSci, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Catalog/ColumnDescriptor.h"
#include "DataMgr/AbstractBuffer.h"

namespace foreign_storage {

class ParquetEncoder {
 public:
  ParquetEncoder(Data_Namespace::AbstractBuffer* buffer) : buffer_(buffer) {}
  virtual ~ParquetEncoder() = default;

  virtual void appendData(int16_t* def_levels,
                          int64_t values_read,
                          int64_t levels_read,
                          int8_t* values) = 0;

 protected:
  Data_Namespace::AbstractBuffer* buffer_;
};

}  // namespace foreign_storage
