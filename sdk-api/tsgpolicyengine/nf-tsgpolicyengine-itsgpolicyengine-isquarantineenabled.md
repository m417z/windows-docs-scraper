# ITSGPolicyEngine::IsQuarantineEnabled

## Description

Indicates whether the authorization plug-in requires a statement of health (SoH) from the user's computer.

## Parameters

### `quarantineEnabled` [out]

Indicates whether the authorization plug-in requires a statement of health from the user's computer. **TRUE** to use RD Gateway to request an SoH from the user's computer; otherwise, **FALSE**.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. If an error code is returned, RD Gateway assumes that an SoH is not required.

## See also

[ITSGPolicyEngine](https://learn.microsoft.com/windows/desktop/api/tsgpolicyengine/nn-tsgpolicyengine-itsgpolicyengine)