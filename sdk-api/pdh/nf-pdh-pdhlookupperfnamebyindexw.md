# PdhLookupPerfNameByIndexW function

## Description

Returns the performance object name or counter name corresponding to the specified index.

## Parameters

### `szMachineName` [in]

**Null**-terminated string that specifies the name of the computer where the specified performance object or counter is located. The computer name can be specified by the DNS name or the IP address. If **NULL**, the function uses the local computer.

### `dwNameIndex` [in]

Index of the performance object or counter.

### `szNameBuffer` [out]

Caller-allocated buffer that receives the **null**-terminated name of the performance object or counter. Set to **NULL** if *pcchNameBufferSize* is zero.

### `pcchNameBufferSize` [in, out]

Size of the *szNameBuffer* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *szNameBuffer* buffer is not large enough to contain the counter name. This return value is expected if *pcchNameBufferSize* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *szNameBuffer* to **NULL** and *pcchNameBufferSize* to 0), and the second time to get the data.

**Windows XP:** You must specify a buffer and buffer size. The function sets *pcchNameBufferSize* to either the required size or the size of the buffer that was used. If the buffer is too small, the function returns PDH_INSUFFICIENT_BUFFER instead of PDH_MORE_DATA. The maximum string size in bytes is PDH_MAX_COUNTER_NAME * sizeof(TCHAR).

The index value that you specify must match one of the index values associated with the objects or counters that were loaded on the computer. The index/name value pairs are stored in the **Counters** registry value in the following registry location.

```
HKEY_LOCAL_MACHINE
   \SOFTWARE
      \Microsoft
         \Windows NT
            \CurrentVersion
               \Perflib
                  Last Counter = highest counter index
                  Last Help = highest help index
                  \009
                     Counters = 2 System 4 Memory...
                     Help = 3 The System Object Type...
                  \supported language, other than English
                     Counters = ...
                     Help = ...
```

> [!NOTE]
> The pdh.h header defines PdhLookupPerfNameByIndex as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhLookupPerfIndexByName](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhlookupperfindexbynamea)