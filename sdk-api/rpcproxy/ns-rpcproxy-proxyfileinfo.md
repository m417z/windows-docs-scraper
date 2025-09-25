# ProxyFileInfo structure

## Description

The **ProxyFileInfo** structure contains information about the interface proxies in the proxy DLL.

## Members

### `pProxyVtblList`

Array of proxy Vtables contained in the proxy DLL. Each array element contains the Vtable for each proxy interface in the DLL.

### `pStubVtblList`

### `pNamesArray`

Array of interface names contained in the proxy DLL.

### `pDelegatedIIDs`

Array of base interface identifiers contained in the proxy DLL. Array elements associated with interfaces that are not delegated are set to null. If no interfaces in the DLL are delegated, *pDelegatedIIDs* is null.

### `pIIDLookupRtn`

Used to search for a given interface in the proxy list.

### `TableSize`

Number of interfaces in the proxy DLL.

### `TableVersion`

Version of the proxy stub. The version can be one of the versions.

| Value | Meaning |
| --- | --- |
| 1 | The .idl file is compiled with the [/0s](https://learn.microsoft.com/windows/desktop/Midl/-os) option. |
| 2 | The .idl file is compiled with the [/0i](https://learn.microsoft.com/windows/desktop/Midl/-oi), **/0ic**, or **/Oicf** option. |
| 6 | The proxy DLL contains an asynchronous interface. |

### `pAsyncIIDLookup`

Used to search for a given asynchronous interface in the proxy list.

### `Filler2`

Not used.

### `Filler3`

Not used.

### `Filler4`

Not used.

### `pstubVtblList`

Array of stub Vtables contained in the proxy DLL. Each array element contains the Vtable for each stub interface in the DLL.