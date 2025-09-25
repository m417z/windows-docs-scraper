# IDiscMaster::Close

## Description

Closes the interface so other applications can use it.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

Content not committed to media through a call to
[RecordDisc](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-recorddisc) is lost.

Closing an already closed interface returns S_OK.

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)