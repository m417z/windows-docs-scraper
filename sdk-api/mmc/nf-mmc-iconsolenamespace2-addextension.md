# IConsoleNameSpace2::AddExtension

## Description

The **IConsoleNameSpace2::AddExtension** method enables the snap-in to add an extension snap-in that dynamically extends the namespace of a selected item.

## Parameters

### `hItem` [in]

A handle to the item to extend with the snap-in specified by *lpClsid*.

### `lpClsid` [in]

A pointer to the **CLSID** of the snap-in that will extend the namespace of the item specified by *hItem*.

## Return value

This method can return one of these values.

## Remarks

When a snap-in calls the
AddExtension method, the namespace extension specified by lpClsid extends only the specific instance of the item specified by hItem. Other items of that type are not affected: Calling
AddExtension is not the same as using the snap-in manager to add an extension to a snap-in. By using the snap-in manager to add an extension to a snap-in, the extension is added to all instances of snap-ins of that type.

In addition, the
AddExtension method only works for items that are directly owned by the snap-in making the
AddExtension call. For example, if a snap-in has a namespace extension that adds an item to its namespace, the snap-in cannot call
AddExtension for the item provided by the namespace extension because the snap-in does not own that item.

A common place to add dynamic namespace extensions is in the [MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand) notification handler of the snap-in's
IComponentData object.

**Note** The extension snap-in must be a namespace extension. In addition, the MMC registry entries for the snap-in to be extended, as well as the extension snap-in, must be set correctly.

To dynamically add other types of extensions (such as context menus, toolbars, property sheets, or taskpads), the snap-in must add the new clipboard format CCF_MMC_DYNAMIC_EXTENSIONS to the data object for the items you want to extend. The
[CCF_MMC_DYNAMIC_EXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-mmc-dynamic-extensions) format uses the
[SMMCDynamicExtensions](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-smmcobjecttypes) structure. For more information, see
[Dynamic Non-Namespace Extensions](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/dynamic-non-namespace-extensions).

If an extension snap-in is intended to be used as a dynamic extension only, that extension snap-in should not be listed in the Available Extensions list box when the primary snap-in is selected in the Snap-in that can be extended box on the snap-in manager's extensions page. To hide an extension in the snap-in manager, add the key "Dynamic Extensions" to the key that represents the node type of the item you want to extend. Then put the CLSIDs of the snap-ins that should only dynamically extend the node type as values under the new key.

#### Examples

The following code example adds the extension snap-in specified by **CLSID_Extension**:

```cpp
IConsoleNameSpace2* pExtensions = NULL;
HRESULT hr = m_pConsole->QueryInterface(IID_IConsoleNameSpace2, reinterpret_cast<void**>(&pExtensions));

if (SUCCEEDED(hr))
{
    hr = pExtensions->AddExtension(m_pStaticRoot, const_cast<CLSID*>(&CLSID_Extension));
    ASSERT(hr == S_OK);
    pExtensions->Release();
}
```

## See also

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)