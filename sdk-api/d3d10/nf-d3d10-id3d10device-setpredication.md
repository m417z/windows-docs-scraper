# ID3D10Device::SetPredication

## Description

Set a rendering predicate.

## Parameters

### `pPredicate` [in]

Type: **[ID3D10Predicate](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10predicate)***

Pointer to a predicate (see [ID3D10Predicate](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10predicate)). A **NULL** value indicates "no" predication; in this case, the value of PredicateValue is irrelevant but will be preserved for [ID3D10Device::GetPredication](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-getpredication).

### `PredicateValue` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, rendering will be affected by when the predicate's conditions are met. If **FALSE**, rendering will be affected when the conditions are not met.

## Remarks

The predicate must be in the "issued" or "signaled" state to be used for predication. While the predicate is set for predication, calls to [ID3D10Asynchronous::Begin](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-begin) and [ID3D10Asynchronous::End](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-end) are invalid.

This method is used to denote that subsequent rendering and resource manipulation commands are not actually performed if the resulting Predicate data of the Predicate is equal to the PredicateValue. However, some Predicates are only hints, so they may not actually prevent operations from being performed.

The primary usefulness of Predication is to allow an application to issue graphics commands without taking the performance hit of spinning, waiting for [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) to return. So, Predication can occur while **ID3D10Asynchronous::GetData** returns S_FALSE. Another way to think of it: an application can also use Predication as a fallback, if it is possible that **ID3D10Asynchronous::GetData** returns S_FALSE. If **ID3D10Asynchronous::GetData** returns S_OK, the application can skip calling the graphics commands manually with its own application logic.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)