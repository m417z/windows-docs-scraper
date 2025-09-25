# CommitTemplateFlags enumeration

## Description

The **CommitTemplateFlags** enumeration type specifies options for saving and deleting templates. It is used by the [Commit](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificatetemplatewritable-commit) method on the [IX509CertificateTemplateWritable](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplatewritable) interface.

## Constants

### `CommitFlagSaveTemplateGenerateOID:1`

Save the template and create an object identifier for it.

### `CommitFlagSaveTemplateUseCurrentOID:2`

Not used.

### `CommitFlagSaveTemplateOverwrite:3`

Not used.

### `CommitFlagDeleteTemplate:4`

Delete the template.

## See also

[Commit](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificatetemplatewritable-commit)

[IX509CertificateTemplateWritable](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificatetemplatewritable)