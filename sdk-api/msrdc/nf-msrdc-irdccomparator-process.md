# IRdcComparator::Process

## Description

The **Process** method
compares two signature streams (seed and source) and produces a needs list, which describes the chunks of file data needed to create
the target file. The seed signature file may be read multiple times, depending on the size of the
source signature file.

## Parameters

### `endOfInput` [in]

Set to **TRUE** if the *inputBuffer* parameter contains all
remaining input.

### `endOfOutput` [out]

Address of a **BOOL** that on successful completion is set to
**TRUE** if all output data has been generated.

### `inputBuffer` [in, out]

Address of a [RdcBufferPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcbufferpointer) structure containing
information about the input buffer. The **m_Used** member of this structure is used to
indicate how much input, if any, was processed during this call.

### `outputBuffer` [in, out]

Address of a [RdcNeedPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneedpointer) structure containing
information about the output buffer. On input the **m_Size** member of this structure
must contain the number of [RdcNeed](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneed) structures in the array
pointed to by the **m_Data** member, and the **m_Used** member
must be zero. On output the **m_Used** member will contain the number of
**RdcNeed** structures in the array pointed to by the
**m_Data** member.

### `rdc_ErrorCode` [out]

The address of a [RDC_ErrorCode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdc_errorcode) enumeration that is
filled with an RDC specific error code if the return value from the
**Process** method is
**E_FAIL**. If this value is **RDC_Win32ErrorCode**, then the
return value of the **Process** method contains the
specific error code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

On successful return, iterate through each [RdcNeed](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneed) structure
returned in the array pointed to by the **m_Data** member of the
*outputBuffer* parameter, and copy the specified chunk of the source or seed data to the
target data.

## See also

[IRdcComparator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdccomparator)

[RDC_ErrorCode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdc_errorcode)

[RdcBufferPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcbufferpointer)

[RdcNeedPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcneedpointer)