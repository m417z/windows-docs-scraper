# IS_SPECIAL_COOKIE macro

## Description

The
**IS_SPECIAL_COOKIE** macro determines whether an **MMC_COOKIE** value passed by MMC in a call to the snap-in's
[IComponent::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-querydataobject) method is a special type of cookie.

## Parameters

### `c`

A value of type **MMC_COOKIE** that you want to evaluate.

## Remarks

You can use this macro to verify that the cookie passed by MMC in its call to [IComponent::QueryDataObject](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-querydataobject) is one of the special values, and then handle the data object appropriately based on the specific value of the cookie (**MMC_MULTI_SELECT_COOKIE** or **MMC_WINDOW_COOKIE**).