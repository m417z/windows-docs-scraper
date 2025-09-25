# IDirectManipulationManager::CreateContent

## Description

The factory method that is used to create an instance of secondary content (such as a panning indicator) inside a viewport.

## Parameters

### `frameInfo` [in, optional]

The frame info provider for the secondary content. This should match the frame info provider used to create the viewport.

### `clsid` [in]

Class identifier (CLSID) of the secondary content. This ID specifies the content type.

### `riid` [in]

IID of the interface.

### `object` [out, retval]

The secondary content object that implements the specified interface.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Primary content is automatically created at the same time as the viewport and has a one-to-one relationship to a viewport. Therefore, it is not possible to create, add, or remove primary content.

Secondary content is created independently from the viewport. There is no limit to how much secondary content can be added or removed from a viewport. All secondary content transforms are derived from those supported by the primary content with specific rules applied based on the intended purpose of the element (identified by its Class identifier (CLSID)).

## See also

[IDirectManipulationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager)