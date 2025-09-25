# NdrDllGetClassObject function

## Description

The **NdrDllGetClassObject** function retrieves the class object of the proxy or stub.

## Parameters

### `rclsid` [in]

Class identifier of the proxy or stub to retrieve.

### `riid` [in]

Interface identifier of the [IPSFactoryBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipsfactorybuffer) interface.

### `ppv` [out]

Address of the output variable that receives the interface pointer requested in *riid*.

### `pProxyFileList` [in]

Pointer to the [ProxyFileInfo](https://learn.microsoft.com/windows/desktop/api/rpcproxy/ns-rpcproxy-proxyfileinfo) structure, which contains information about the proxy and stub.

### `pclsid` [in]

Pointer to the class identifier of the proxy or stub. Specify *pclsid* if the **PROXY_CLSID** constant is defined in the source code or as a C compiler option.

### `pPSFactoryBuffer` [in]

Pointer to the [IPSFactoryBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipsfactorybuffer) object. The pointer is contained in the global variable, gPFactory, defined in RpcProxy.h.

## Return value

Returns S_OK on success.