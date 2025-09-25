# IStreamBufferInitialize::SetSIDs

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetSIDs** method sets the security identifiers (SIDs) that are used to protect access to the backing files.

## Parameters

### `cSIDs` [in]

Specifies the size of the array given in the *ppSID* parameter.

### `ppSID` [in]

Pointer to an array of **SID** structures, of size *cSIDs*.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | Null pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

At run time, the Stream Buffer Source and Sink filters create various Win32 objects, such as mutexes, so that access to the backing files is synchronized across threads. Each of the filters maintains a list of SIDs that are used to protect these objects. By default, the filters inherit their SIDs from the hosting process. An application can use the **SetSIDs** method to override the default SIDs.

If you call this method, do so before locking the sink filter or loading a file in the source filter. It is recommended that all of the filters be given the same SIDs.

* **Important**Setting less-privileged SIDs can create a security issue.

Note that this method does not apply to content recording files, which are protected by the discretionary access-control lists (DACLs) of the directory structure.

## See also

[IStreamBufferInitialize Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferinitialize)