# IAdviseSink2::OnLinkSrcChange

## Description

Notifies the container that registered the advise sink that a link source has changed (either name or location), enabling the container to update the link's moniker.

## Parameters

### `pmk` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface identifying the source of a linked object.

## Remarks

A container of linked objects implements this method to receive notification in the event of a change in the moniker of its link source.

**OnLinkSrcChange** is called by the OLE link object when it receives the [OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) notification from the link-source (object) application. The link object updates its moniker and sends the **OnLinkSrcChange** notification to containers that have implemented [IAdviseSink2](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink2).

### Notes to Implementers

Nothing prevents a link object from notifying its container of the moniker change by calling [OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) instead of **OnLinkSrcChange**. In practice, however, overloading **OnRename** to mean either that a link object's moniker has changed or that an embedded object's server name has changed makes it difficult for applications to determine which of these events has occurred. If the two events trigger different processing, as will often be the case, calling a different method for each makes the job of determining which event occurred much easier.

## See also

[IAdviseSink2](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink2)

[IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename)