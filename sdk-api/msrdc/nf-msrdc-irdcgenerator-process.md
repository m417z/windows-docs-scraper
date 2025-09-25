# IRdcGenerator::Process

## Description

The **Process** method processes the input
data and produces 0 or more output bytes. This method must be called repeatedly until the
**BOOL** pointed to by *endOfOutput* is set to
**TRUE**.

## Parameters

### `endOfInput` [in]

Set to **TRUE** when the input buffer pointed to by the
*inputBuffer* parameter contains the remaining input available.

### `endOfOutput` [out]

Address of a **BOOL** that is set to **TRUE** when the
processing is complete for all data.

### `inputBuffer` [in, out]

Address of an [RdcBufferPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcbufferpointer) structure that
contains the input buffer. On successful return, the **m_Used** member of this structure
will be filled with the number of bytes by this call.

### `depth` [in]

The number of levels of signatures to generate. This must match the number of levels specified when the
generator was created.

### `outputBuffers` [out]

The address of an array of [RdcBufferPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcbufferpointer) structures that
will receive the output buffers. The **m_Used** member of these structures will be filled with the number of bytes returned in the buffer.

### `rdc_ErrorCode` [out]

The address of an [RDC_ErrorCode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdc_errorcode) enumeration that is
filled with an RDC specific error code if the return value from the
**Process** method is
**E_FAIL**. If this value is **RDC_Win32ErrorCode**, then the
return value of the **Process** method contains the
specific error code.

## Return value

This method can return one of these values.

## See also

[IRdcGenerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgenerator)

[RDC_ErrorCode](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdc_errorcode)

[RdcBufferPointer](https://learn.microsoft.com/windows/win32/api/msrdc/ns-msrdc-rdcbufferpointer)