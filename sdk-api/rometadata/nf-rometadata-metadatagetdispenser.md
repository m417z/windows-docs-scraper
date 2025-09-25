# MetaDataGetDispenser function

## Description

 Creates a dispenser class.

## Parameters

### `rclsid` [in]

Type: **REFCLSID**

This parameter must be **CLSID_CorMetaDataDispenser**.

### `riid` [in]

Type: **REFIID**

The interface to implement. This parameter can be either **IID_IMetaDataDispenser** or **IID_IMetaDataDispenserEx**.

### `ppv` [out]

Type: **LPVOID***

The dispenser class. The class implements **IMetaDataDispenser** or **IMetaDataDispenserEx.**

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.