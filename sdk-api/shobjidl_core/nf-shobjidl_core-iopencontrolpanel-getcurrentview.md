# IOpenControlPanel::GetCurrentView

## Description

Gets the most recent Control Panel view: Classic view or Category view.

## Parameters

### `pView` [out]

Type: **CPVIEW***

A pointer that receives the most recent view. Valid values are as follows:

#### CPVIEW_CLASSIC (0x0)

0x0. Classic view.

#### CPVIEW_ALLITEMS (CPVIEW_CLASSIC)

0x0. **Windows 7 and later**. Equivalent to CPVIEW_CLASSIC.

#### CPVIEW_CATEGORY (0x1)

0x1. Category view.

#### CPVIEW_HOME (0x1)

0x1. **Windows 7 and later**. Equivalent to CPVIEW_CATEGORY.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.