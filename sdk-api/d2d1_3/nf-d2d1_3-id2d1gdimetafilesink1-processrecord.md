# ID2D1GdiMetafileSink1::ProcessRecord

## Description

Provides access to metafile records, including their type, data, and flags.

## Parameters

### `recordType`

Type: **DWORD**

The type of metafile record being processed. Please see [MS-EMF](https://learn.microsoft.com/openspecs/windows_protocols/ms-emf/91c257d7-c39d-4a36-9b1f-63e3f73d30ca) and [MS-EMFPLUS](https://learn.microsoft.com/openspecs/windows_protocols/ms-emfplus/5f92c789-64f2-46b5-9ed4-15a9bb0946c6) for a list of record types.

### `recordData` [in, optional]

Type: **const void***

The data contained in this record. Please see [MS-EMF](https://learn.microsoft.com/openspecs/windows_protocols/ms-emf/91c257d7-c39d-4a36-9b1f-63e3f73d30ca) and [MS-EMFPLUS](https://learn.microsoft.com/openspecs/windows_protocols/ms-emfplus/5f92c789-64f2-46b5-9ed4-15a9bb0946c6) for information on record data layouts.

### `recordDataSize`

Type: **UINT**

TThe size of the data pointed to by recordData.

### `flags`

Type: **UINT32**

The set of flags set for this record. Please see [MS-EMF](https://learn.microsoft.com/openspecs/windows_protocols/ms-emf/91c257d7-c39d-4a36-9b1f-63e3f73d30ca) and [MS-EMFPLUS](https://learn.microsoft.com/openspecs/windows_protocols/ms-emfplus/5f92c789-64f2-46b5-9ed4-15a9bb0946c6) for information on record flags.

## Return value

Type: **HRESULT**

S_OK if successful, otherwise a failure HRESULT.

## Remarks

For details on the EMF and EMF+ formats, please see Microsoft technical documents [MS-EMF](https://learn.microsoft.com/openspecs/windows_protocols/ms-emf/91c257d7-c39d-4a36-9b1f-63e3f73d30ca) and [MS-EMFPLUS](https://learn.microsoft.com/openspecs/windows_protocols/ms-emfplus/5f92c789-64f2-46b5-9ed4-15a9bb0946c6).

## See also

[ID2D1GdiMetafileSink1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafilesink)

[[MS-EMFPLUS]: Enhanced Metafile Format Plus Extensions](https://learn.microsoft.com/openspecs/windows_protocols/ms-emfplus/5f92c789-64f2-46b5-9ed4-15a9bb0946c6)

[[MS-EMF]: Enhanced Metafile Format](https://learn.microsoft.com/openspecs/windows_protocols/ms-emf/91c257d7-c39d-4a36-9b1f-63e3f73d30ca)