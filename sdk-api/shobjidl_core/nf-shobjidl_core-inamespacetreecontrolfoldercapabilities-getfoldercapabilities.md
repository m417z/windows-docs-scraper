# INameSpaceTreeControlFolderCapabilities::GetFolderCapabilities

## Description

Gets a folder's capability to be filtered through the [System.IsPinnedToNameSpaceTree](https://learn.microsoft.com/windows/desktop/properties/props-system-ispinnedtonamespacetree) property key value and change notification registration status.

## Parameters

### `nfcMask` [in]

Type: **[NSTCFOLDERCAPABILITIES](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nstcfoldercapabilities)**

The capabilities for which this method should retrieve values. Specify one or both of the following:

#### NSTCFC_PINNEDITEMFILTERING (0x00000001)

0x00000001. The [System.IsPinnedToNameSpaceTree](https://learn.microsoft.com/windows/desktop/properties/props-system-ispinnedtonamespacetree) property exists on this folder and filtering based on that property value is supported.

#### NSTCFC_DELAY_REGISTER_NOTIFY (0x00000002)

0x00000002. Registration for change notifications is delayed until the folder is expanded in the navigation pane.

### `pnfcValue` [out]

Type: **[NSTCFOLDERCAPABILITIES](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nstcfoldercapabilities)***

Pointer to a value that, when this method returns successfully, receives the capabilities requested in *nfcMask*. Except in the case of NSTCFC_NONE, bit values in positions not specifically requested in *nfcMask* do not necessarily reflect the capabilities and should not be used.

#### NSTCFC_NONE (0x00000000)

0x00000000. The [System.IsPinnedToNameSpaceTree](https://learn.microsoft.com/windows/desktop/properties/props-system-ispinnedtonamespacetree) property does not exist on this folder. Filtering is not supported.

#### NSTCFC_PINNEDITEMFILTERING (0x00000001)

0x00000001. The [System.IsPinnedToNameSpaceTree](https://learn.microsoft.com/windows/desktop/properties/props-system-ispinnedtonamespacetree) property exists on this folder and filtering based on that property value is supported.

#### NSTCFC_DELAY_REGISTER_NOTIFY (0x00000002)

0x00000002. Registration for change notifications is delayed until the folder is expanded in the navigation pane.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.