# ID2D1Effect::SetInputCount

## Description

Allows the application to change the number of inputs to an effect.

## Parameters

### `inputCount`

Type: **UINT32**

The number of inputs to the effect.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_INVALIDARG | One or more arguments are invalid. |
| E_OUTOFMEMORY | Failed to allocate necessary memory. |

## Remarks

Most effects do not support a variable number of inputs. Use [ID2D1Properties::GetValue](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1properties-getvalue(uint32_byte_uint32)) with the **D2D1_PROPERTY_MIN_INPUTS** and **D2D1_PROPERTY_MAX_INPUTS** values to determine the number of inputs supported by an effect.

If the input count is less than the minimum or more than the maximum supported inputs, the call will fail.

If the input count is unchanged, the call will succeed with **S_OK**.

Any inputs currently selected on the effect will be unaltered by this call unless the number of inputs is made smaller. If the number of inputs is made smaller, inputs beyond the selected range will be released.

If the method fails, the existing input and input count will remain unchanged.

## See also

[ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect)

[ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode))

[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)

[ID2D1Effect::GetOutput](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1effect-getoutput)

[ID2D1Image](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1image)