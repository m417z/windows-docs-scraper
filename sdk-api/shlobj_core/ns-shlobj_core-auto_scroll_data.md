# AUTO_SCROLL_DATA structure

## Description

[**AUTO_SCROLL_DATA** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Specifies scrolling parameters and keeps track of the last scroll operation.

## Members

### `iNextSample`

Type: **int**

A value that indicates the number of times the [DAD_AutoScroll](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-dad_autoscroll) function has stored data in the structure. The parameter is reset to `0` after it equals 2.

### `dwLastScroll`

Type: **DWORD**

A **DWORD** that indicates the time of the last scroll. The scroll time is also stored in the **dwTimes** parameter indexed by the current value of **iNextSample**.

### `bFull`

Type: **BOOL**

A value that is used to determine whether the [DAD_AutoScroll](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-dad_autoscroll) function should succeed. This parameter is set to **TRUE** when the **iNextSample** parameter is equal to NUM_POINTS.

#### (FALSE)

Default. Indicates that the window should not scroll.

#### (TRUE)

Indicates that the window should scroll.

### `pts`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)[NUM_POINTS]**

A pointer to the current scroll coordinates. The index of this array is **iNextSample**.

### `dwTimes`

Type: **DWORD[NUM_POINTS]**

A **DWORD** that indicates the current scroll time. The index of this array is **iNextSample**.

## Remarks

NUM_POINTS is currently set to `3`.

## See also

[DAD_AutoScroll](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-dad_autoscroll)