# DSCLASSCREATIONINFO structure

## Description

The **DSCLASSCREATIONINFO** structure is used with the [IDsDisplaySpecifier::GetClassCreationInfo](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-getclasscreationinfo) method to hold data about the class creation wizard objects for an object class.

## Members

### `dwFlags`

Contains a set of flags that indicate which members of this structure contain valid data. This can be a combination of one or more of the following values.

#### DSCCIF_HASWIZARDDIALOG

The **clsidWizardDialog** member is valid.

#### DSCCIF_HASWIZARDPRIMARYPAGE

The **clsidWizardPrimaryPage** member is valid.

### `clsidWizardDialog`

Contains the class identifier of the class creation wizard dialog box. This member is not used if **dwFlags** does not contain **DSCCIF_HASWIZARDDIALOG**.

### `clsidWizardPrimaryPage`

Contains the class identifier of the primary property page of the class creation wizard. This member is not used if **dwFlags** does not contain **DSCCIF_HASWIZARDPRIMARYPAGE**.

### `cWizardExtensions`

Contains the number of elements in the **aWizardExtensions** array.

### `aWizardExtensions`

Contains an array of the class identifiers of the property page extensions. **cWizardExtensions** specifies the number of elements in this array.

## See also

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[IDsDisplaySpecifier::GetClassCreationInfo](https://learn.microsoft.com/windows/desktop/api/dsclient/nf-dsclient-idsdisplayspecifier-getclasscreationinfo)