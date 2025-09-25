# _EXT_TYPED_DATA structure

## Description

The EXT_TYPED_DATA structure is passed to and returned from the [DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)
[Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request) operation. It contains the input and output parameters for the operation as well as specifying which particular suboperation to perform.

## Members

### `Operation`

Specifies which suboperation the [DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)
[Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request) operation should perform. The interpretation of some of the other members depends on **Operation**. For a list of possible suboperations, see [EXT_TDOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ne-wdbgexts-_ext_tdop).

### `Flags`

Specifies the bit flags describing the target's memory in which the data resides. If no flags are present, the data is considered to be in virtual memory. One of the following flags may be present:

| Flag | Description |
| --- | --- |
| EXT_TDF_PHYSICAL_DEFAULT | The typed data is in physical memory, and this physical memory uses the default memory caching. |
| EXT_TDF_PHYSICAL_CACHED | The typed data is in physical memory, and this physical memory is cached. |
| EXT_TDF_PHYSICAL_UNCACHED | The typed data is in physical memory, and this physical memory is uncached. |
| EXT_TDF_PHYSICAL_WRITE_COMBINED | The typed data is in physical memory, and this physical memory is write-combined. |

### `InData`

Specifies typed data to be used as input to the operation. For details about this structure, see [DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data).

The interpretation of **InData** depends on the value of **Operation**.

### `OutData`

Receives typed data as output from the operation. Any suboperation that returns typed data to **OutData** initially copies the contents of **InData** to **OutData**, then modifies **OutData** in place, so that the input parameters in **InData** are also present in **OutData**. For details about this structure, see [DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data).

The interpretation of **OutData** depends on the value of **Operation**.

### `InStrIndex`

Specifies the position of an ANSI string to be used as input to the operation. **InStrIndex** can be zero to indicate that the input parameters do not include an ANSI string.

The position of the string is relative to the base address of this EXT_TYPED_DATA structure. The string must follow this structure, so **InStrIndex** must be greater than the size of this structure. The string is part of the input to the operation and **InStrIndex** must be smaller than *InBufferSize*, the size of the input buffer passed to [Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request).

The interpretation of the string depends on the value of **Operation**.

### `In32`

Specifies a 32-bit parameter to be used as input to the operation.

The interpretation of **In32** depends on the value of **Operation**.

### `Out32`

Receives a 32-bit value as output from the operation.

The interpretation of **Out32** depends on the value of **Operation**.

### `In64`

Specifies a 64-bit parameter to be used as input to the operation.

The interpretation of **In64** depends on the value of **Operation**.

### `Out64`

Receives a 64-bit value as output from the operation.

The interpretation of **Out64** depends on the value of **Operation**.

### `StrBufferIndex`

Specifies the position to return an ANSI string as output from the operation. **StrBufferIndex** can be zero if no ANSI string is to be received from the operation.

The position of the string is relative to the base address of the returned EXT_TYPED_DATA structure. The string must follow the structure, so **StrBufferIndex** must be greater than the size of this structure. The string is part of the output from the suboperation, and **StrBufferIndex** plus **StrBufferChars** must be smaller than *OutBufferSize*, the size of the output buffer passed to [Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request).

The interpretation of the string depends on the value of **Operation**.

### `StrBufferChars`

Specifies the size in characters of the ANSI string buffer specified by **StrBufferIndex**.

### `StrCharsNeeded`

Receives the number of characters needed by the string buffer specified by **StrBufferIndex**.

### `DataBufferIndex`

Set to zero.

### `DataBufferBytes`

Set to zero.

### `DataBytesNeeded`

Set to zero,

### `Status`

Receives the status code returned by the operation. This is the same value returned by [Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request).

### `Reserved`

Set to zero.

## Remarks

The members of this structure are used as the input and output parameters to the [DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)
[Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request) operation. The interpretation of most of the parameters depends on the particular suboperation being performed, as specified by the **Operation** member.

This structure can optionally specify additional data--using the members **InStrIndex** and **StrBufferIndex**--that is included with the structure. This additional data is specified relative to the address of the instance of this structure. When used with the DEBUG_REQUEST_EXT_TYPED_DATA_ANSI **Request** operation, the additional data is included in the *InBuffer* and *OutBuffer* (as appropriate) and should be included in the size of these two buffers.

## See also

[DEBUG_REQUEST_EXT_TYPED_DATA_ANSI](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-request-ext-typed-data-ansi)

[DEBUG_TYPED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ns-wdbgexts-_debug_typed_data)

[EXT_TDOP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/ne-wdbgexts-_ext_tdop)

[Request](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugadvanced3-request)