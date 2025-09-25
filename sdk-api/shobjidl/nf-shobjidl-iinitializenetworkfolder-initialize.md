# IInitializeNetworkFolder::Initialize

## Description

Initializes a network folder, as specified.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

The Shell namespace location for this data source, as an IDList.

### `pidlTarget` [in]

Type: **PCIDLIST_ABSOLUTE**

The target namespace location, as an IDList. This is used when the data source is aliased into the namespace. This parameter specifies the location of the network item that the data source will represent. See [InitializeEx](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder3-initializeex) and in [PERSIST_FOLDER_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-persist_folder_target_info) see the *pidlTargetFolder* definition for more information.

### `uDisplayType` [in]

Type: **UINT**

The display type of the network resource this data source will represent. This is one of the RESOURCEDISPLAYTYPE_XXX values found in winnetwk.h.

### `pszResName` [in]

Type: **LPCWSTR**

The network resource name. for example, \\server or \\server\share. this is passed to the WNet in the [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig).*lpRemoteName* field.

### `pszProvider` [in, optional]

Type: **LPCWSTR**

Optional network provider, as in the [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig).*lpProvider* field.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IInitializeNetworkFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iinitializenetworkfolder)

[InitializeEx](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder3-initializeex)

[NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)

[PERSIST_FOLDER_TARGET_INFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-persist_folder_target_info)

