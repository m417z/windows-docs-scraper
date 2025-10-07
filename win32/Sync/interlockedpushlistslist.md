# InterlockedPushListSList function

## Description

Inserts a singly-linked list at the front of another singly linked list.

Access to the lists is synchronized on a multiprocessor system.

```cpp
PSLIST_ENTRY  FASTCALL InterlockedPushListSList(
  _Inout_ PSLIST_HEADER ListHead,
  _Inout_ PSLIST_ENTRY  List,
  _Inout_ PSLIST_ENTRY  ListEnd,
  _In_    ULONG         Count
);
```

## Parameters

### ListHead [in, out]

Pointer to an **SLIST_HEADER** structure that represents the head of a singly linked list.
The list specified by the *List* and *ListEnd* parameters is inserted at the front of this list.

### List [in, out]

Pointer to an [SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry) structure that represents the first item in the list to be inserted.

### ListEnd [in, out]

Pointer to an [SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry) structure that represents the last item in the list to be inserted.

### Count [in]

The number of items in the list to be inserted.

## Returns

The return value is the previous first item in the list specified by the *ListHead* parameter.
If the list was previously empty, the return value is **NULL**.

## Remarks

All list items must be aligned on a **MEMORY_ALLOCATION_ALIGNMENT** boundary; otherwise, this function will behave unpredictably.
See **_aligned_malloc**.

**Windows 8 and Windows Server 2012:** This function has been superceded by [InterlockedPushListSListEx](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushlistslistex).

When compiling with **NTDDI_VERSION** set to **NTDDI_WIN8** or greater, calls to **InterlockedPushListSList** will go to **InterlockedPushListSListEx** instead.

## See also

[Interlocked Singly Linked Lists](https://learn.microsoft.com/windows/win32/sync/interlocked-singly-linked-lists)

[InterlockedPopEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpopentryslist)

[InterlockedPushEntrySList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushentryslist)

[InterlockedPushListSListEx](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedpushlistslistex)

[InterlockedFlushSList](https://learn.microsoft.com/windows/win32/api/interlockedapi/nf-interlockedapi-interlockedflushslist)

[SLIST_ENTRY](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-slist_entry)

[Using Singly Linked Lists](https://learn.microsoft.com/windows/win32/sync/using-singly-linked-lists)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)