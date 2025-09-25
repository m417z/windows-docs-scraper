# HypothesisResult structure

## Description

The **HypothesisResult** structure contains information about a hypothesis returned from a helper class. The hypothesis is obtained via a call to [GetLowerHypotheses](https://learn.microsoft.com/windows/desktop/api/ndhelper/nf-ndhelper-inetdiaghelper-getlowerhypotheses).

## Members

### `hypothesis`

Type: **[HYPOTHESIS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ns-ndhelper-hypothesis)**

Information for a specific hypothesis.

### `pathStatus`

Type: **[DIAGNOSIS_STATUS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-diagnosis_status)**

The status of the child helper class and its children.

If the hypothesis or any of its children indicated **DS_CONFIRMED** in a call to [LowHealth](https://learn.microsoft.com/windows/desktop/api/ndhelper/nf-ndhelper-inetdiaghelper-lowhealth), then this value will be **DS_CONFIRMED**. If no problems exist in such a call, the value will be **DS_REJECTED**. The value will be **DS_INDETERMINATE** if the health of the component is not clear.

## See also

[DIAGNOSIS_STATUS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ne-ndhelper-diagnosis_status)

[GetLowerHypotheses](https://learn.microsoft.com/windows/desktop/api/ndhelper/nf-ndhelper-inetdiaghelper-getlowerhypotheses)

[HYPOTHESIS](https://learn.microsoft.com/windows/desktop/api/ndhelper/ns-ndhelper-hypothesis)

[LowHealth](https://learn.microsoft.com/windows/desktop/api/ndhelper/nf-ndhelper-inetdiaghelper-lowhealth)