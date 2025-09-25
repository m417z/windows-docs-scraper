# IRdcSignatureReader::ReadSignatures

## Description

The
**ReadSignatures** method
reads a block of signatures from the current position.

## Parameters

### `rdcSignaturePointer` [in, out]

Address of a [RdcSignaturePointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignaturepointer) structure. On
input the **m_Size** member of this structure must contain the number of
[RdcSignature](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignature) structures in the array pointed to by the
**m_Data** member, and the **m_Used** member must be zero. On
output the **m_Used** member will contain the number of
**RdcSignature** structures in the array pointed to by the
**m_Data** member.

### `endOfOutput` [out]

Address of a **BOOL** that is set to **TRUE** if the end of
the signatures has been read.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcSignatureReader](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcsignaturereader)

[RdcSignaturePointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcsignaturepointer)