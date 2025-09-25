# IUISimplePropertySet::GetValue

## Description

Retrieves the value identified by a property key.

## Parameters

### `key` [in]

Type: **REFPROPERTYKEY**

The [Property Key](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties) of interest.

### `value` [out]

Type: **PROPVARIANT***

When this method returns, contains a pointer to the value for
*key*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

#### Examples

The following example demonstrates a custom implementation of [IUISimplePropertySet](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuisimplepropertyset) for both item and Command galleries.

The CItemProperties class in this example is derived from [IUISimplePropertySet](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuisimplepropertyset) and, in addition to the required method **IUISimplePropertySet::GetValue**, implements a set of helper functions for initialization and index tracking.

```cpp
//
//  PURPOSE:    Implementation of IUISimplePropertySet.
//
//  COMMENTS:
//              Three gallery-specific helper functions added.
//

class CItemProperties
  : public CComObjectRootEx<CComMultiThreadModel>
  , public IUISimplePropertySet
{
  public:

  // COM map for QueryInterface of IUISimplePropertySet.
  BEGIN_COM_MAP(CItemProperties)
    COM_INTERFACE_ENTRY(IUISimplePropertySet)
  END_COM_MAP()

  // Required method that enables property key values to be
  // retrieved on gallery collection items.
  STDMETHOD(GetValue)(REFPROPERTYKEY key, PROPVARIANT *ppropvar)
  {
    HRESULT hr;

    // A Command gallery.
		  // _isCommandGallery set on item initialization.
    if (_isCommandGallery)
    {			
      if(key == UI_PKEY_CommandId && _isCommandGallery)
      {
			     // Return a pointer to the CommandId of the item.
        return InitPropVariantFromUInt32(_cmdID, ppropvar);
      }			
    }
    // An item gallery.
    else
    {
      if (key == UI_PKEY_Label)
      {
        // Return a pointer to the item label string.
        return UIInitPropertyFromString(
                 UI_PKEY_Label, g_labels[_index], ppropvar);
      }
      else if(key == UI_PKEY_ItemImage)
      {
        if (NULL == _spimgItem)
        {
          hr = CreateUIImageFromBitmapResource(
                 MAKEINTRESOURCE(IDB_GALLERYITEM), &_spimgItem);
          if (FAILED(hr))
          {
            return hr;
          }
        }
        // Return a pointer to the item image.
        return UIInitPropertyFromImage(
                 UI_PKEY_ItemImage, _spimgItem, ppropvar);
      }			
    }
    return E_NOTIMPL;
  }

  // Initialize an item in an item gallery collection at the specified index.
  void Initialize(int index)
  {
    _index = index;
    _cmdID = 0;
    _isCommandGallery = false;
  }

  // Initialize a Command in a Command gallery.
  void InitializeAsCommand(__in UINT cmdID)
  {
    _index = 0;
    _cmdID = cmdID;
    _isCommandGallery = true;
  }

  // Gets the index of the selected item in an item gallery.
  int GetIndex()
  {
    return _index;
  }

private:
  int _index;
  int _cmdID;
  bool _isCommandGallery;
  CComPtr<IUIImage> _spimgItem;	
};
```

## See also

[IUISimplePropertySet](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuisimplepropertyset)

[Property Keys](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)