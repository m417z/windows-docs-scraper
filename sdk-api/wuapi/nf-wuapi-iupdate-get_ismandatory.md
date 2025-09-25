# IUpdate::get_IsMandatory

## Description

Gets a Boolean value that indicates whether the installation of the update is mandatory.

This property is read-only.

## Parameters

## Remarks

If you try to mark a mandatory update as hidden, an error occurs.

Mandatory updates are updates to the Windows Update Agent (WUA) infrastructure. WUA may not require all mandatory updates to continue operating. However, these updates frequently improve performance or increase the number of products that WUA can offer. We recommend that you install all mandatory updates.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)