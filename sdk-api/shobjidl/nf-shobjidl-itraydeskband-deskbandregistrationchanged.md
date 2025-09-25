# ITrayDeskBand::DeskBandRegistrationChanged

## Description

Refreshes the deskband registration cache.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method immediately after making a change to the deskband registration. For example, through the CLSID_StdComponentCategoriesMgr object.