# SHCreateMemStream function

## Description

Creates a memory stream using a similar process to [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal).

## Parameters

### `pInit` [in, optional]

Type: **const BYTE***

A pointer to a buffer of size *cbInit*. The contents of this buffer are used to set the initial contents of the memory stream. If this parameter is **NULL**, the returned memory stream does not have any initial content.

### `cbInit` [in]

Type: **UINT**

The number of bytes in the buffer pointed to by *pInit*. If *pInit* is set to **NULL**, *cbInit* must be zero.

## Return value

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

On success, returns a pointer to the created memory stream. Returns **NULL** if the stream object could not be allocated.

## Remarks

Prior to Windows Vista, this function was not included in the public Shlwapi.h file, nor was it exported by name from Shlwapi.dll. To use it on earlier systems, you must call it directly from the Shlwapi.dll file as ordinal 12.

This function creates a memory stream. This is an implementation of the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface that stores its contents in memory. **SHCreateMemStream** differs from [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) in the following ways.

* Thread safety. The stream created by **SHCreateMemStream** is thread-safe as of Windows 8. On earlier systems, the stream is not thread-safe. The stream created by [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) is thread-safe.
* Initial contents. **SHCreateMemStream** accepts the initial contents in the form of a buffer. [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) accepts the initial contents in the form of an HGLOBAL.
* Access to contents. **SHCreateMemStream** does not allow direct access to the stream contents. [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) permits access through [GetHGlobalFromStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-gethglobalfromstream).
* Failure information. If **SHCreateMemStream** returns **NULL**, it was unable to allocate the necessary memory. Callers should assume the cause is E_OUTOFMEMORY.
* Support for [IStream::Clone](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-clone). Prior to Windows 8, the stream created by **SHCreateMemStream** does not support **IStream::Clone**. The stream created by [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) does. As of Windows 8, the stream created by **SHCreateMemStream** does support **IStream::Clone**.
* The stream returned by **SHCreateMemStream** returns S_FALSE from [IStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) if you attempt to read past the end of the buffer. The stream returned by [CreateStreamOnHGlobal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-createstreamonhglobal) returns S_OK and sets *pcbRead to 0 if you attempt to read past the end of the buffer.