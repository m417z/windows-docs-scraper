# WdfWdmDriverGetWdfDriverHandle function

## Description

[Applies to KMDF only]

The **WdfWdmDriverGetWdfDriverHandle** method returns a handle to the framework driver object that is associated with a specified Windows Driver Model (WDM) driver object.

## Parameters

### `DriverObject` [in]

A pointer to a WDM driver object.

## Return value

**WdfWdmDriverGetWdfDriverHandle** returns a handle to a framework driver object. A system bug check occurs if the *DriverObject* pointer is **NULL**.