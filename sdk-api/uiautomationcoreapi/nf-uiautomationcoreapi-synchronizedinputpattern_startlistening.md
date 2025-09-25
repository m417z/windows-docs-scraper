# SynchronizedInputPattern_StartListening function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Causes the UI Automation provider to start listening for mouse or keyboard input.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The *control pattern* object.

### `inputType` [in]

Type: **[SynchronizedInputType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-synchronizedinputtype)**

A combination of values from the [SynchronizedInputType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-synchronizedinputtype) enumerated type specifying the type of input for which to listen.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.