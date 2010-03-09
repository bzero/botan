/*
* Basic Allocators
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_BASIC_ALLOC_H__
#define BOTAN_BASIC_ALLOC_H__

#include <botan/internal/mem_pool.h>

namespace Botan {

/*
* Malloc Allocator
*/
class Malloc_Allocator : public Allocator
   {
   public:
      void* allocate(u32bit);
      void deallocate(void*, u32bit);

      std::string type() const { return "malloc"; }
   };

/*
* Locking Allocator
*/
class Locking_Allocator : public Pooling_Allocator
   {
   public:
      std::string type() const { return "locking"; }
   private:
      void* alloc_block(u32bit);
      void dealloc_block(void*, u32bit);
   };

}

#endif
