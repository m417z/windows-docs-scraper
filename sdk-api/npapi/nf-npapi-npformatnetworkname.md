# NPFormatNetworkName function

## Description

Formats a network name in a provider-specific format for display in a control.

## Parameters

### `lpRemoteName` [in]

Pointer to the network name to format.

### `lpFormattedName` [out]

Pointer to a string that receives the formatted name.

### `lpnLength` [in, out]

Pointer to **DWORD** that specifies the size, in characters, of the *lpFormattedName* buffer. If the return value of this function is WN_MORE_DATA, *lpnLength* contains the required buffer size, in characters.

### `dwFlags` [in]

Bitfield that indicates the type of format being requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WNFMT_MULTILINE** | The provider should place backslash n (\\n) where line breaks should appear in the name. The full name should be expressed. |
| **WNFMT_ABBREVIATED** | The provider should shorten the network name so that the information most useful for the user will fit in the available space. |

In addition, the following flag, which acts as a modifier to the preceding flags, can be included by using a bitwise-**OR** operation.

| Value | Meaning |
| --- | --- |
| **WNFMT_INENUM** | The network name is presented in the context of an enumeration where the name of the "container" appears immediately before the network name in the enumeration. This allows network providers to remove redundant information from the formatted name, providing a less cluttered display for the user. |

### `dwAveCharPerLine` [in]

Specifies the average number of characters that will fit on a single line where the network name is being presented. Specifically, this value is defined as the width of the control divided by the **tmAveCharWidth** field of the
[TEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-textmetrica) structure from the font used for display in the control.

## Return value

If the function succeeds, it should return WN_SUCCESS.

If the function fails, it should return the following value. All other errors will be ignored, and the unformatted network name will be used.

| Return code | Description |
| --- | --- |
| **WN_MORE_DATA** | The input buffer is too small. |

## Remarks

This function allows network vendors to trim or modify network names before they are presented to the user. For example, in the common **Open** dialog box, the **Drives** combo box presents all connected resources and their associated network name. Before each item is displayed, **NPFormatNetworkName** is called, and the network provider has the option of editing the name so it will fit in the combo box. More important, the network provider can edit the name to present the most significant portion of the network name to the user.

Note that **NPFormatNetworkName** is not routed to each network provider like most of the other network provider functions are. Each network vendor need worry only about formatting their own network name. They can assume that only names produced by their network provider driver will be passed to **NPFormatNetworkName**.

The WNFMT_ flags are typically passed at various places in the user interface as described in the following table. No assumptions should be made about what flags are passed where; this table is provided solely to help each network vendor decide the best method for modifying their network name.

| Display location | WNFMT_ MULTILINE | WNFMT_ ABBREVIATED | WNFMT_ INENUM |
| --- | --- | --- | --- |
| File Manager **Connection** dialog box, **Drive** combo box, selection. (The selection section of the combo box is the upper rectangle, above the list section, which displays the current selection.) |  | X |  |
| File Manager **Connection** dialog box, **Drive** combo box, list. (The list section of the combo box is the list box that appears below the selection portion of the combo box.) | X |  |  |
| File Manager, **Shared Directories** list. |  | X | X |
| File Manager **Disconnect Network Drive** list. | X |  |  |
| File Manager, toolbar, combo box, selection. |  | X |  |
| File Manager, toolbar, combo box, list. | X |  |  |
| Common **Open** and **Save** dialog boxes, **Drive** combo box, selection. |  | X |  |
| Common **Open** and **Save** dialog boxes, **Drive** combo box, list. |  | X |  |