# NdrDllCanUnloadNow function

## Description

The **NdrDllCanUnloadNow** function determines whether the DLL that implements the proxy and stub is still in use. If not, the caller can safely unload the DLL from memory.

## Parameters

### `pPSFactoryBuffer` [in]

Pointer to the [CStdPSFactoryBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipsfactorybuffer) object. The pointer is contained in the global variable, gPFactory, defined in RpcProxy.h.

## Return value

Returns S_OK if the DLL can be unloaded. Otherwise, it returns S_FALSE if the DLL cannot be unloaded.