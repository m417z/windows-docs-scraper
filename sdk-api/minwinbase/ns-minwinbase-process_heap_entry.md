# PROCESS_HEAP_ENTRY structure

## Description

Contains information about a heap element. The
[HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) function uses a
**PROCESS_HEAP_ENTRY** structure to enumerate the
elements of a heap.

## Members

### `lpData`

A pointer to the data portion of the heap element.

To initiate a [HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) heap enumeration, set
**lpData** to **NULL**.

If **PROCESS_HEAP_REGION** is used in the **wFlags** member,
**lpData** points to the first virtual address used by the region.

If **PROCESS_HEAP_UNCOMMITTED_RANGE** is used in **wFlags**,
**lpData** points to the beginning of the range of uncommitted memory.

### `cbData`

The size of the data portion of the heap element, in bytes.

If **PROCESS_HEAP_REGION** is used in **wFlags**,
**cbData** specifies the total size, in bytes, of the address space that is reserved for
this region.

If **PROCESS_HEAP_UNCOMMITTED_RANGE** is used in **wFlags**,
**cbData** specifies the size, in bytes, of the range of uncommitted memory.

### `cbOverhead`

The size of the data used by the system to maintain information about the heap element, in bytes. These
overhead bytes are in addition to the **cbData** bytes of the data portion of the heap
element.

If **PROCESS_HEAP_REGION** is used in **wFlags**,
**cbOverhead** specifies the size, in bytes, of the heap control structures that
describe the region.

If **PROCESS_HEAP_UNCOMMITTED_RANGE** is used in **wFlags**,
**cbOverhead** specifies the size, in bytes, of the control structures that describe
this uncommitted range.

### `iRegionIndex`

A handle to the heap region that contains the heap element. A heap consists of one or more regions of virtual
memory, each with a unique region index.

In the first heap entry returned for most heap regions,
[HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) uses the
**PROCESS_HEAP_REGION** in the **wFlags** member. When this value
is used, the members of the **Region** structure contain additional information
about the region.

The [HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc) function sometimes uses the
[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc) function to allocate large blocks from a
growable heap. The heap manager treats such a large block allocation as a separate region with a unique region
index. [HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk) does not use
**PROCESS_HEAP_REGION** in the heap entry returned for a large block region, so the
members of the **Region** structure are not valid. You can use the
[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery) function to get additional information
about a large block region.

### `wFlags`

The properties of the heap element. Some values affect the meaning of other members of this
**PROCESS_HEAP_ENTRY** data structure. The
following values are defined.

| Value | Meaning |
| --- | --- |
| **PROCESS_HEAP_ENTRY_BUSY**<br><br>0x0004 | The heap element is an allocated block.<br><br>If **PROCESS_HEAP_ENTRY_MOVEABLE** is also specified, the **Block** structure becomes valid. The **hMem** member of the **Block** structure contains a handle to the allocated, moveable memory block. |
| **PROCESS_HEAP_ENTRY_DDESHARE**<br><br>0x0020 | This value must be used with **PROCESS_HEAP_ENTRY_BUSY**, indicating that the heap element is an allocated block. |
| **PROCESS_HEAP_ENTRY_MOVEABLE**<br><br>0x0010 | This value must be used with **PROCESS_HEAP_ENTRY_BUSY**, indicating that the heap element is an allocated block.<br><br>The block was allocated with **LMEM_MOVEABLE** or **GMEM_MOVEABLE**, and the **Block** structure becomes valid. The **hMem** member of the **Block** structure contains a handle to the allocated, moveable memory block. |
| **PROCESS_HEAP_REGION**<br><br>0x0001 | The heap element is located at the beginning of a region of contiguous virtual memory in use by the heap.<br><br>The **lpData** member of the structure points to the first virtual address used by the region; the **cbData** member specifies the total size, in bytes, of the address space that is reserved for this region; and the **cbOverhead** member specifies the size, in bytes, of the heap control structures that describe the region.<br><br>The **Region** structure becomes valid. The **dwCommittedSize**, **dwUnCommittedSize**, **lpFirstBlock**, and **lpLastBlock** members of the structure contain additional information about the region. |
| **PROCESS_HEAP_UNCOMMITTED_RANGE**<br><br>0x0002 | The heap element is located in a range of uncommitted memory within the heap region.<br><br>The **lpData** member points to the beginning of the range of uncommitted memory; the **cbData** member specifies the size, in bytes, of the range of uncommitted memory; and the **cbOverhead** member specifies the size, in bytes, of the control structures that describe this uncommitted range. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Block`

This structure is valid only if both the **PROCESS_HEAP_ENTRY_BUSY** and
**PROCESS_HEAP_ENTRY_MOVEABLE** are specified in **wFlags**.

### `DUMMYUNIONNAME.Block.hMem`

Handle to the allocated, moveable memory block.

### `DUMMYUNIONNAME.Block.dwReserved`

Reserved; not used.

### `DUMMYUNIONNAME.Region`

This structure is valid only if the **wFlags** member specifies
**PROCESS_HEAP_REGION**.

### `DUMMYUNIONNAME.Region.dwCommittedSize`

Number of bytes in the heap region that are currently committed as free memory blocks, busy memory blocks,
or heap control structures.

This is an optional field that is set to zero if the number of committed bytes is not available.

### `DUMMYUNIONNAME.Region.dwUnCommittedSize`

Number of bytes in the heap region that are currently uncommitted.

This is an optional field that is set to zero if the number of uncommitted bytes is not available.

### `DUMMYUNIONNAME.Region.lpFirstBlock`

Pointer to the first valid memory block in this heap region.

### `DUMMYUNIONNAME.Region.lpLastBlock`

Pointer to the first invalid memory block in this heap region.

## See also

[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc)

[HeapAlloc](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapalloc)

[HeapWalk](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapwalk)

[VirtualAlloc](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc)

[VirtualQuery](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualquery)