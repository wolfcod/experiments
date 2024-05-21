#ifndef CHIPSEC_H
#define CHIPSEC_H


#define DEVICE_NAME_U L"\\Device\\chipsec_hlpr"
#define DEVICE_NAME_DOS L"\\DosDevices\\chipsec_hlpr"

#define RDWRPCI_DEVICE_NAME_WIN32      "\\\\.\\chipsec_hlpr"


#ifndef CTL_CODE
	#pragma message("CTL_CODE undefined. Include winioctl.h or wdm.h")
#endif

#define CHIPSEC_CTL_ACCESS    (FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define CLOSE_DRIVER \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define READ_PCI_CFG_REGISTER \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x807, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define WRITE_PCI_CFG_REGISTER \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x808, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_READ_PHYSMEM  \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x809, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_WRITE_PHYSMEM \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x80a, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_ALLOC_PHYSMEM \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_LOAD_UCODE_PATCH \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x80b, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_WRMSR \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x80c, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_RDMSR \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x80d, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define READ_IO_PORT \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x80e, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define WRITE_IO_PORT \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x80f, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define GET_CPU_DESCRIPTOR_TABLE \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_SWSMI \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )
#define IOCTL_CPUID \
        CTL_CODE( FILE_DEVICE_UNKNOWN, 0x813, METHOD_BUFFERED, CHIPSEC_CTL_ACCESS )

#endif  // CHIPSEC_H
