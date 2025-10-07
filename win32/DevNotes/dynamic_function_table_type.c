typedef struct _DYNAMIC_FUNCTION_TABLE {
    LIST_ENTRY ListEntry;
    PRUNTIME_FUNCTION FunctionTable;
    LARGE_INTEGER Reserved1;
    ULONG64 MinimumAddress;
    ULONG64 MaximumAddress;
    ULONG64 BaseAddress;
    PVOID Reserved2[2];
    PWSTR OutOfProcessCallbackDll;
    FUNCTION_TABLE_TYPE Type;
    ULONG EntryCount;
} DYNAMIC_FUNCTION_TABLE, * PDYNAMIC_FUNCTION_TABLE;