# IOleClientSite::RequestNewObjectLayout

## Description

Asks a container to resize the display site for embedded objects.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Client site does not support requests for new layout. |

## Remarks

This method can either increase or decrease the space. Currently, there is no standard mechanism by which a container can negotiate how much room an object would like. When such a negotiation is defined, responding to this method will be optional for containers.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)