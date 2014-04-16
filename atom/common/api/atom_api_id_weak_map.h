// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Copyright (c) 2012 Intel Corp. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_API_ATOM_API_ID_WEAK_MAP_H_
#define ATOM_COMMON_API_ATOM_API_ID_WEAK_MAP_H_

#include <map>
#include <vector>

#include "atom/common/v8/scoped_persistent.h"
#include "base/basictypes.h"
#include "native_mate/wrappable.h"

namespace atom {

namespace api {

// Like ES6's WeakMap, but the key is Integer and the value is Weak Pointer.
class IDWeakMap : public mate::Wrappable<IDWeakMap> {
 public:
  IDWeakMap();

  static void Initialize(v8::Handle<v8::Object> exports);

 private:
  virtual ~IDWeakMap();

  static void WeakCallback(v8::Isolate* isolate,
                           v8::Persistent<v8::Object>* value,
                           IDWeakMap* self);

  int32_t Add(v8::Isolate* isolate, v8::Handle<v8::Object> object);
  v8::Handle<v8::Value> Get(int32_t key);
  bool Has(int32_t key) const;
  std::vector<int32_t> Keys() const;
  void Remove(int32_t key);
  int GetNextID();

  int32_t next_id_;
  std::map<int32_t, RefCountedV8Object> map_;

  DISALLOW_COPY_AND_ASSIGN(IDWeakMap);
};

}  // namespace api

}  // namespace atom

#endif  // ATOM_COMMON_API_ATOM_API_ID_WEAK_MAP_H_
