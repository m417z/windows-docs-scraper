# RdcSignaturePointer structure

## Description

The
**RdcSignaturePointer** structure
describes an array
of [RdcSignature](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignature) structures. The
**RdcSignaturePointer** structure is used as both input
and output by the
[IRdcSignatureReader::ReadSignatures](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcsignaturereader-readsignatures)
method.

## Members

### `m_Size`

Contains the number of [RdcSignature](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignature) structures in
array pointed to by **m_Data**.

### `m_Used`

When the structure is passed to the
[IRdcSignatureReader::ReadSignatures](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcsignaturereader-readsignatures)
method, this member should be zero. On return this member will contain the number of
[RdcSignature](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignature) structures that were filled.

### `m_Data`

Address of an array of [RdcSignature](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignature) structures.

## See also

[IRdcSignatureReader::ReadSignatures](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcsignaturereader-readsignatures)

[RdcSignature](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignature)

[Remote Differential Compression Structures](https://learn.microsoft.com/previous-versions/windows/desktop/rdc/remote-differential-compression-structures)