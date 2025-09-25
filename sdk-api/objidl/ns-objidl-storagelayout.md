# StorageLayout structure

## Description

The
**StorageLayout** structure describes a single block of data, including its name, location, and length. To optimize a compound file, an application or layout tool passes an array of
**StorageLayout** structures in a call to
[ILayoutStorage::LayoutScript](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-layoutscript).

## Members

### `LayoutType`

The type of element to be written. Values are taken from the
[STGTY](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-stgty) enumeration. **STGTY_STREAM** means read the block of data named by **pwcsElementName**. **STGTY_STORAGE** means open the storage specified in **pwcsElementName**. **STGTY_REPEAT** is used in multimedia applications to interface audio, video, text, and other elements. An opening **STGTY_REPEAT** value means that the elements that follow are to be repeated a specified number of times. The closing **STGTY_REPEAT** value marks the end of those elements that are to be repeated. Nested **STGTY_REPEAT** value pairs are permitted.

### `pwcsElementName`

The null-terminated Unicode string name of the storage or stream. If the element is a substorage or embedded object, the fully qualified storage path must be specified; for example, "RootStorageName\SubStorageName\Substream".

### `cOffset`

Where the value of the **LayoutType** member is **STGTY_STREAM**, this flag specifies the beginning offset into the steam named in the **pwscElementName** member.

Where **LayoutType** is **STGTY_STORAGE**, this flag should be set to zero.

Where **LayoutType** is **STGTY_REPEAT**, this flag should be set to zero.

### `cBytes`

Length, in bytes, of the data block named in **pwcsElementName**.

Where **LayoutType** is **STGTY_STREAM**, **cBytes** specifies the number of bytes to read at **cOffset** from the stream named in **pwcsElementName**.

Where **LayoutType** is **STGTY_STORAGE**, this flag is ignored.

Where **LayoutType** is **STGTY_REPEAT**, a positive **cBytes** specifies the beginning of a repeat block. **STGTY_REPEAT** with zero **cBytes** marks the end of a repeat block.

A beginning block value of **STG_TOEND** specifies that elements in a following block are to be repeated after each stream has been completely read.

## Remarks

An array of
**StorageLayout** structures might appear as follows.

```cpp
StorageLayout arrScript[]=
    // Read first 2k of "WordDocument" stream
    {STGTY_STREAM,L"WordDocument",{0,0},{0,2048}},

    //Test if "ObjectPool\88112233" storage exists
    {STGTY_STORAGE,L"ObjectPool\\88112233",{0,0},{0,0}},

    //Read 2k at offset 1048 of "WordDocument" stream
    {STGTY_STREAM,L"WordDocument",{0,10480},{0,2048}},

    //Interlace "Audio", "Video", and "Caption" streams
    {STGTY_REPEAT,NULL,0,STG_TOEND},
        {STGTY_STREAM,L"Audio", {0,0},{0,2048}},    // 2k of Audio
        {STGTY_STREAM,L"Video", {0,0},{0,65536}},   // 64k of Video
        {STGTY_STREAM,L"Caption", {0,0},{0,128}},   // 128b of text
    {STGTY_REPEAT,NULL, {0,0},{0,0}}
};
```

**Note** The parameters *cOffset* and *cBytes* are **LARGE_INTEGER** structures, used to represent a 64-bit signed integer value as a union of two 32-bit members. The two 32-bit members must be represented as a **LARGE_INTEGER** structure with **DWORD** LowPart and **LONG** HighPart as the structure members. (LowPart specifies the low-order 32 bits and HighPart specifies the high-order 32 bits.) If your compiler has built-in support for 64-bit integers, use the **QuadPart** member of the **LARGE_INTEGER** structure to store the 64-bit integer.

## See also

[ILayoutStorage::LayoutScript](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilayoutstorage-layoutscript)