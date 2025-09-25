## Description

The **IPrintOemPrintTicketProvider::PublishPrintTicketHelperInterface** method publishes the print ticket helper interface for either Unidrv or Pscript5 user interface (UI) plug-ins.

## Parameters

### `pHelper` [in]

A pointer to an **IUnknown** interface, which should be cast to one of the following interfaces: For Unidrv plug-ins, the print ticket helper interface is **IPrintCoreHelperUni**; for Pscript5 plug-ins, the print ticket helper interface is **IPrintCoreHelperPS**.

## Return value

**IPrintOemPrintTicketProvider::PublishPrintTicketHelperInterface** should return **S_OK** if the operation succeeds. Otherwise, this method should return a standard COM error code.

## Remarks

If the plug-in maintains a handle to the helper object, the plug-in is responsible for later releasing that handle when it is no longer needed.

If **IPrintOemPrintTicketProvider::PublishPrintTicketHelperInterface** uses the helper interface, it should cache a pointer to the interface, and increment the reference count (by means of a call to the interface's **AddRef** method). If this method successfully increments the reference count, it should return **S_OK**.