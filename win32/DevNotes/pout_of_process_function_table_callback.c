typedef
DWORD
OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK (
    _In_ HANDLE Process,
    _In_ PVOID TableAddress,
    _Out_ PDWORD Entries,
    _Outptr_result_buffer_(*Entries) PRUNTIME_FUNCTION* Functions
    );
typedef OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK *POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK;