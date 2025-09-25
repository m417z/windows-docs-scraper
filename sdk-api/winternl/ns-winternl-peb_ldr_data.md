# PEB_LDR_DATA structure

## Description

[This structure may be altered in future versions of Windows.]

Contains information about the loaded modules for the process.

## Members

### `Reserved1`

Reserved for internal use by the operating system.

### `Reserved2`

Reserved for internal use by the operating system.

### `InMemoryOrderModuleList`

The head of a doubly-linked list that contains the loaded modules for the process. Each item in the list is a pointer to an **LDR_DATA_TABLE_ENTRY** structure. For more information, see Remarks.

## Remarks

The **LIST_ENTRY** structure is defined as follows:

``` syntax
typedef struct _LIST_ENTRY {
   struct _LIST_ENTRY *Flink;
   struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, *RESTRICTED_POINTER PRLIST_ENTRY;
```

The **LDR_DATA_TABLE_ENTRY** structure is defined as follows:

``` syntax
typedef struct _LDR_DATA_TABLE_ENTRY {
    PVOID Reserved1[2];
    LIST_ENTRY InMemoryOrderLinks;
    PVOID Reserved2[2];
    PVOID DllBase;
    PVOID Reserved3[2];
    UNICODE_STRING FullDllName;
    BYTE Reserved4[8];
    PVOID Reserved5[3];
    union
    {
        ULONG CheckSum;
        PVOID Reserved6;
    };
    ULONG TimeDateStamp;
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;

```

## See also

[PEB](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-peb)