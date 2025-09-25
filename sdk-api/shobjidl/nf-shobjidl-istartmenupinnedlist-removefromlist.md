# IStartMenuPinnedList::RemoveFromList

## Description

**Windows Vista**: Removes an item from the **Start** menu pinned list, which is the list in the upper left position of the **Start** menu.

**Windows 7**: Removes an item from the **Start** menu pinned list and unpins the item from the taskbar.

**Windows 8**: Unpins the item from the taskbar but does not remove the item from the Start screen. Items cannot be programmatically removed from Start; they can only be unpinned by the user or removed as part of a program's uninstallation.

## Parameters

### `pitem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the item to unpin.

## Return value

Type: **HRESULT**

* Returns S_OK if the item was successfully removed from the list of pinned items and/or the taskbar.
* Returns S_OK if the item was not pinned at all.
* Returns a standard error code otherwise.

## Remarks

Because an application cannot know if any of its installed shortcuts have been pinned, this method should be called on any application shortcut being removed from the system. This includes shortcuts placed on the desktop during installation and those added to the **Start** menu's **All Programs** list.

It is recommended that all applications use this method to clean up their pinned items during their uninstallation process. Unpinning the application shortcut is not required, but it is strongly recommended for reliability.

This method does not remove the original shortcut represented by *pitem*. It removes its pinned representation from the **Start** menu and/or taskbar. Once an item has been removed (unpinned) through this method, then the application can delete the original shortcut.

If an item is pinned to both the **Start** menu and the taskbar, one call to this method removes it from both locations.

**Note** If your application is using the Windows Installer (MSI) framework to perform the uninstallation, you do not need to call this method explicitly; MSI will make the call to unpin the shortcuts for you.

#### Examples

This example demonstrates the use of **IStartMenuPinnedList::RemoveFromList**.

```cpp

HRESULT hr = CoInitializeEx(NULL,COINIT_APARTMENTTHREADED);

if (SUCCEEDED(hr))
{
    IShellItem *pitem;
    hr = SHCreateItemFromParsingName(TEXT("Path to the shortcut"),
                                     NULL,
                                     IID_PPV_ARGS(&pitem));

    //
    // Do setup work here to remove the link, including the unpinning
    // of the item.
    //

    if (SUCCEEDED(hr))
    {
        IStartMenuPinnedList *pStartMenuPinnedList;

        hr = CoCreateInstance(CLSID_StartMenuPin,
                              NULL,
                              CLSCTX_INPROC_SERVER,
                              IID_PPV_ARGS(&pStartMenuPinnedList));

        if (SUCCEEDED(hr))
        {
            hr = pStartMenuPinnedList->RemoveFromList(pitem);
            pStartMenuPinnedList->Release();
        }

        pitem->Release();
    }
}

CoUnitialize();
```