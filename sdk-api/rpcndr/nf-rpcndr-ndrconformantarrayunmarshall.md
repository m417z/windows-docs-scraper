# NdrConformantArrayUnmarshall function

## Description

The **NdrConformantArrayUnmarshall** function unmarshals a conformant array.

## Parameters

### `pStubMsg` [in]

Pointer to a [MIDL_STUB_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcndr/ns-rpcndr-midl_stub_message) structure that maintains the current status of the RPC stub. This structure is for internal use only and should not be modified.

### `ppMemory` [out]

Address to a pointer to the buffer where the conformant array is unmarshalled. If set to **null**, or if the *fMustAlloc* is set to **TRUE**, the stub will allocate the memory.

### `pFormat` [in]

Pointer to the format string description.

### `fMustAlloc` [in]

Flag that specifies whether the stub must allocate the memory into which the conformant array is to be marshalled. Specify **TRUE** if RPC must allocate *ppMemory*.

## Return value

Returns **null** upon success. If an error occurs, the function throws one of the following exception codes.

| Return code | Description |
| --- | --- |
| **RPC_BAD_STUB_DATA** | The network is incorrect. |
| **RPC_X_INVALID_BOUND** | The network is incorrect. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |
| **STATUS_ACCESS_VIOLATION** | An access violation occurred. |
| **RPC_S_INTERNAL_ERROR** | An error occurred in RPC. |

## Remarks

The **NdrConformantArrayUnmarshall** function is used by both the client- and server-side stub to unmarshall a conformant array. The stub might allocate memory as necessary. For example, pArray in the sample on this page points to a conformant array.

**NdrConformantArrayUnmarshall** should only be called in the context of an RPC stub, after the client or server stub has been initialized.

#### Examples

```cpp
void  ConfArray([in] long size,
        [in,size_is(size)] long *pArray);         // conformant array

```