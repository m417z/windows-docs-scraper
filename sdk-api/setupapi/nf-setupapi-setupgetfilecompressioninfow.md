# SetupGetFileCompressionInfoW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetFileCompressionInfo** function examines a physical file to determine if it is compressed and gets its full path, size, and the size of the uncompressed target file.

Note that this function is obsolete and has been replaced by
[SetupGetFileCompressionInfoEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetfilecompressioninfoexa). Do not use
**SetupGetFileCompressionInfo**, instead always use
**SetupGetFileCompressionInfoEx**.

## Parameters

### `SourceFileName` [in]

File name of the file about which information is required. If the file is not found on the source media exactly as named, the file is searched for with up to two alternate "compressed-form" names. For example, if the file is F:\x86\cmd.exe and it is not found, F:\mpis\cmd.ex_ is searched for and, if that is not found, a search is done for F:\x86\cmd.ex$. You should use a null-terminated string.

### `ActualSourceFileName` [in, out]

Pointer to a variable that receives the full path of the file that it has been able to locate. The caller can free the pointer with a call to **LocalFree**. The path is valid only if the function returns NO_ERROR. Note that if the version of SetupAPI.dll is less than 5.0.2195, then the caller needs to use the exported function **MyFree** from SetupAPI to free the memory allocated by this function, rather then using **LocalFree**. See the Remarks section.

### `SourceFileSize` [in, out]

Pointer to a variable in which this function returns the size of the file in its current form which is the current size of the file named by *ActualSourceFileName*. The size is determined by examining the source file; it is not retrieved from an INF file. The source file size is valid only if the function returns NO_ERROR.

### `TargetFileSize` [in, out]

Pointer to a variable in which this function returns the size the file will occupy when it is uncompressed or copied. If the file is not compressed, this value will be the same as *SourceFileSize*. The size is determined by examining the file; it is not retrieved from an INF file. The target file size is valid only if the function returns NO_ERROR.

### `CompressionType` [in, out]

Pointer to a variable in which this function returns a value indicating the type of compression used on *ActualSourceFileName*. The compression type is valid only if the function returns NO_ERROR. The value can be one of the following flags.

#### FILE_COMPRESSION_NONE

The source file is not compressed with a recognized compression algorithm.

#### FILE_COMPRESSION_WINLZA

The source file is compressed with LZ compression.

#### FILE_COMPRESSION_MSZIP

The source file is compressed with MSZIP compression.

##### - CompressionType.FILE_COMPRESSION_MSZIP

The source file is compressed with MSZIP compression.

##### - CompressionType.FILE_COMPRESSION_NONE

The source file is not compressed with a recognized compression algorithm.

##### - CompressionType.FILE_COMPRESSION_WINLZA

The source file is compressed with LZ compression.

## Return value

The function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that indicates the outcome of the file search. The error code can be one of the following values.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not use
**SetupGetFileCompressionInfo**, instead always use
[SetupGetFileCompressionInfoEx](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetfilecompressioninfoexa).

Because
**SetupGetFileCompressionInfo** determines the compression by referencing the physical file, your setup application should ensure that the file is present before calling
**SetupGetFileCompressionInfo**.

Note that if the version of SetupAPI.dll is less than 5.0.2195, then the caller needs to use the exported function **MyFree** from SetupAPI to free the memory allocated by this function, rather then using **LocalFree**. If the call to **LocalFree** causes an Access Violation, you should solve the problem by using **MyFree**.

The following is an example of how to obtain the **MyFree** function from the SetupAPI.dll:

``` syntax
typedef VOID (WINAPI* MYFREEFUNC)(LPVOID lpBuff);
   MYFREEFUNC MyFree;

   HMODULE hDll=NULL;
   hDll = GetModuleHandle("SETUPAPI.DLL");
   MyFree = (MYFREEFUNC)GetProcAddress(hDll, "MyFree");
   ...
   other code here to prepare file queue
   ...
   PTSTR lpActualSourceFileName;
   SetupGetFileCompressionInfo(...,&lpActualSourceFileName,...,...,...);
   ...
   MyFree(lpActualSourceFileName);
```

> [!NOTE]
> The setupapi.h header defines SetupGetFileCompressionInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupDecompressOrCopyFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdecompressorcopyfilea)