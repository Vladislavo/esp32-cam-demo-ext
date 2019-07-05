/*
 * This file is not a part of the OpenMV project.
 * Initiative of Vladislav Rykov (rykovinternational@gmail.com)
 *
 * OV7670 driver.
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "sccb.h"
#include "ov7670.h"
#include "ov7670_regs.h"
#include <stdio.h>

/*
static const uint8_t default_regs[][2] = {
    {GAIN	, 0x00},
    {BLUE	, 0x80},
    {RED	, 0x80},
    {VREF	, 0x0A},
    {COM1	, 0x00},
    {BAVE	, 0x00},
    {GbAVE	, 0x00},
    {AECHH	, 0x00},
    {RAVE	, 0x00},
    {COM2	, 0x01},
    {COM3	, 0x06},
    {COM4 	, 0x00},
    {COM5	, 0x01},
    {COM6	, 0x43},
    {AECH	, 0x40},
    {CLKRC	, 0x80},
    {COM7	, 0x04},
    {COM8	, 0x8F},
    {COM9	, 0x4A},
    {COM10	, 0x02},
    {HSTART	, 0x16},
    {HSTOP	, 0x04},
    {VSTRT	, 0x02},
    {VSTOP	, 0x7A},
    {PSHFT	, 0x00},
    {MVFP	, 0x3F},
    {LAEC	, 0x00},
    {ADCCTR0	, 0x04},
    {ADCCTR1	, 0x02},
    {ADCCTR2	, 0x01},
    {ADCCTR3	, 0x00},
    {AEW	, 0x75},
    {AEB	, 0x63},
    {VPT	, 0xD4},
    {BBIAS	, 0x80},
    {GbBIAS	, 0x80},
    {EXHCH	, 0x00},
    {EXHCL	, 0x00},
    {ADVFL	, 0x00},
    {ADVFH	, 0x00},
    {YAVE	, 0x00},
    {HSYST	, 0x08},
    {HSYEN	, 0x30},
    {HREF	, 0x24},
    {CHLF	, 0x08},
    {ARBLM	, 0x11},
    {ADC	, 0x3F},
    {ACOM	, 0x01},
    {OFON	, 0x00},
    {TSLB	, 0x04},
    {COM11	, 0x0A},
    {COM12	, 0x68},
    {COM13	, 0x88},
    {COM14	, 0x00},
    {EDGE	, 0x00},
    {COM15	, 0xD0},
    {COM16	, 0x08},
    {COM17	, 0x00},
    {AWBC1	, 0x14},
    {AWBC2	, 0xF0},
    {AWBC3	, 0x45},
    {AWBC4	, 0x61},
    {AWBC5	, 0x51},
    {AWBC6	, 0x79},
    {REG4B	, 0x00},
    {DNSTH	, 0x00},
    {MTX1	, 0x40},
    {MTX2	, 0x34},
    {MTX3	, 0x0C},
    {MTX4	, 0x17},
    {MTX5	, 0x29},
    {MTX6	, 0x40},
    {BRIGHT	, 0x00},
    {CONTRAS	, 0x40},
    {CONTRAS_CENTER	, 0x80},
    {MTXS	, 0x1E},
    {LCC1	, 0x00},
    {LCC2	, 0x00},
    {LCC3	, 0x50},
    {LCC4	, 0x30},
    {LCC5	, 0x00},
    {MANU	, 0x80},
    {MANV	, 0x80},
    {GFIX	, 0x00},
    {GGAIN	, 0x00},
    {DBLV	, 0x0A},
    {AWBCTR3	, 0x02},
    {AWBCTR2	, 0x55},
    {AWBCTR1	, 0xC0},
    {AWBCTR0	, 0x9A},
    {SCALING_XSC	, 0x3A},
    {SCALING_YSC	, 0x35},
    {SCALING_DCWCTR	, 0x11},
    {SCALING_PCLK_DIV	, 0x00},
    {REG74	, 0x00},
    {REG75	, 0x0F},
    {REG76	, 0x01},
    {REG77	, 0x10},
    {SLOP	, 0x24},
    {GAM1	, 0x04},
    {GAM2	, 0x07},
    {GAM3	, 0x10},
    {GAM4	, 0x28},
    {GAM5	, 0x36},
    {GAM6	, 0x44},
    {GAM7	, 0x52},
    {GAM8	, 0x60},
    {GAM9	, 0x6C},
    {GAM10	, 0x78},
    {GAM11	, 0x8C},
    {GAM12	, 0x9E},
    {GAM13	, 0xBB},
    {GAM14	, 0xD2},
    {GAM15	, 0xE5},
    {RGB444	, 0x00},
    {DM_LNL	, 0x00},
    {DM_LNH	, 0x00},
    {LCC6	, 0x50},
    {LCC7	, 0x50},
    {BD50ST	, 0x99},
    {BD60ST	, 0x7F},
    {HAECC1	, 0xC0},
    {HAECC2	, 0x90},
    {SCALING_PCLK_DELAY	, 0x02},
    {NT_CTRL	, 0x00},
    {BD50MAX	, 0x0F},
    {HAECC3	, 0xF0},
    {HAECC4	, 0xC1},
    {HAECC5	, 0xF0},
    {HAECC6	, 0xC1},
    {HAECC7	, 0x14},
    {BD60MAX	, 0x0F},
    {STR_OPT	, 0x00},
    {STR_R	, 0x80},
    {STR_G	, 0x80},
    {STR_B	, 0x80},
    {ABLC1	, 0x00},
    {THL_ST	, 0x80},
    {THL_DLT	, 0x04},
    {AD_CHB	, 0x00},
    {AD_CHR	, 0x00},
    {AD_CHGb	, 0x00},
    {AD_CHGr	, 0x00},
    {SATCTR	, 0xC0},
};
*/


static const uint8_t default_regs[][2] = {
    {COM7, 0x80},
	{TSLB,  0x04},	/* OV */
	{COM7, 0x04},	/* RGB */
	// {CLKRC, 0x01},
	/*
	 * Set the hardware window.  These values from OV don't entirely
	 * make sense - hstop is less than hstart.  But they work...
	 */
	{HSTART, 0x13},	{HSTOP, 0x01},
	{HREF, 0xb6},	{VSTRT, 0x02},
	{VSTOP, 0x7a},	{VREF, 0x0a},

	{COM3, 0},	{COM14, 0},
	/* Mystery scaling numbers */
	{SCALING_XSC, 0x3a},		{SCALING_YSC, 0x35},
	{SCALING_DCWCTR, 0x11},		{SCALING_PCLK_DIV, 0xf0},
	{SCALING_PCLK_DELAY,/* 0x02 changed to 1*/0x02},
	{COM10, 0x26},		{COM15, 0xD0},
	/* Gamma curve values */
	{0x7a, 0x20},		{0x7b, 0x10},
	{0x7c, 0x1e},		{0x7d, 0x35},
	{0x7e, 0x5a},		{0x7f, 0x69},
	{0x80, 0x76},		{0x81, 0x80},
	{0x82, 0x88},		{0x83, 0x8f},
	{0x84, 0x96},		{0x85, 0xa3},
	{0x86, 0xaf},		{0x87, 0xc4},
	{0x88, 0xd7},		{0x89, 0xe8},
	/* AGC and AEC parameters.  Note we start by disabling those features,
	   then turn them only after tweaking the values. */
	{COM8, 0xB0},
	{GAIN, 0},	{AECH, 0},
	{COM4, 0x40}, /* magic reserved bit */
// TEKKER MOD
//	{COM9, 0x18}, /* 4x gain + magic rsvd bit */
  { COM9, 0x6A }, /* 128x gain ceiling; 0x8 is reserved bit */
	{BD50MAX, 0x05},	{BD60MAX, 0x07},
	{AEW, 0x95},	{AEB, 0x33},
	{VPT, 0xe3},	{HAECC1, 0x78},
	{HAECC2, 0x68},	{0xa1, 0x03}, /* magic */
	{HAECC3, 0xd8},	{HAECC4, 0xd8},
	{HAECC5, 0xf0},	{HAECC6, 0x90},
	{HAECC7, 0x94},
	{0x30,0},{0x31,0},//disable some delays
	/* Almost all of these are magic "reserved" values.  */
	{COM5, 0x61},	{COM6, 0x4b},
	{0x16, 0x02},		{MVFP, 0x07},
	{0x21, 0x02},		{0x22, 0x91},
	{0x29, 0x07},		{0x33, 0x0b},
	{0x35, 0x0b},		{0x37, 0x1d},
	{0x38, 0x71},		{0x39, 0x2a},
	{COM12, 0x78},	{0x4d, 0x40},
	{0x4e, 0x20},		{GFIX, 0},
	/*{0x6b, 0x4a},*/		{0x74,0x10},
	{0x8d, 0x4f},		{0x8e, 0},
	{0x8f, 0},		{0x90, 0},
	{0x91, 0},		{0x96, 0},
	{0x9a, 0},		{0xb0, 0x84},
	{0xb1, 0x0c},		{0xb2, 0x0e},
	{0xb3, 0x82},		{0xb8, 0x0a},

	/* More reserved magic, some of which tweaks white balance */
	{0x43, 0x0a},		{0x44, 0xf0},
	{0x45, 0x34},		{0x46, 0x58},
	{0x47, 0x28},		{0x48, 0x3a},
	{0x59, 0x88},		{0x5a, 0x88},
	{0x5b, 0x44},		{0x5c, 0x67},
	{0x5d, 0x49},		{0x5e, 0x0e},
	{0x6c, 0x0a},		{0x6d, 0x55},
	{0x6e, 0x11},		{0x6f, 0x9e}, /* it was 0x9F "9e for advance AWB" */
	{0x6a, 0x40},		{BLUE, 0x40},
	{RED, 0x60},

	/* Matrix coefficients */
	{0x4f, 0x80},		{0x50, 0x80},
	{0x51, 0x00},		{0x52, 0x22},
	{0x53, 0x5e},		{0x54, 0x80},
	{0x56, 0x40},		{0x58, 0x9e},
	{0x59, 0x88},		{0x5a, 0x88},
	{0x5b, 0x44},		{0x5c, 0x67},
	{0x5d, 0x49},		{0x5e, 0x0e},
	{0x69, 0x00},		{0x6a, 0x40},
	{0x6b, 0x0a},		{0x6c, 0x0a},
	{0x6d, 0x55},		{0x6e, 0x11},
	{0x6f, 0x9f},

	{COM16, 0x08},	{EDGE, 0},
	{0x75, 0x05},		{REG76, 0xe1},
	{0x4c, 0},		{0x77, 0x01},
	{COM13, /*0xc3*/0x48},	{0x4b, 0x09},
	{0xc9, 0x60},		/*{COM16, 0x38},*/
	{0x56, 0x40},

	{0x34, 0x11},		{COM11, 0x0A},
	{0xa4, 0x82/*Was 0x88*/},		{0x96, 0},
	{0x97, 0x30},		{0x98, 0x20},
	{0x99, 0x30},		{0x9a, 0x84},
	{0x9b, 0x29},		{0x9c, 0x03},
	{0x9d, 0x4c},		{0x9e, 0x3f},
	{0x78, 0x04},

	/* Extra-weird stuff.  Some sort of multiplexor register */
	{0x79, 0x01},		{0xc8, 0xf0},
	{0x79, 0x0f},		{0xc8, 0x00},
	{0x79, 0x10},		{0xc8, 0x7e},
	{0x79, 0x0a},		{0xc8, 0x80},
	{0x79, 0x0b},		{0xc8, 0x01},
	{0x79, 0x0c},		{0xc8, 0x0f},
	{0x79, 0x0d},		{0xc8, 0x20},
	{0x79, 0x09},		{0xc8, 0x80},
	{0x79, 0x02},		{0xc8, 0xc0},
	{0x79, 0x03},		{0xc8, 0x40},
	{0x79, 0x05},		{0xc8, 0x30},
	{0x79, 0x26},

//  {UNDOC_COLOR_CORRECTION, 0x8C}, // Undocumented color correction, set earlier to 0x84 but test this...
	{0xff, 0xff},	/* END MARKER */
};

static void frame_control(
    sensor_t *sensor,
    uint8_t hstart, 
    uint8_t hstop, 
    uint8_t vstart, 
    uint8_t vstop) 
{
    SCCB_Write(sensor->slv_addr, HSTART, hstart >> 3);
    SCCB_Write(sensor->slv_addr, HSTOP, hstop >> 3);
    SCCB_Write(sensor->slv_addr, HREF, ((hstop & 0x07) << 3) | (hstart & 0x07));

    SCCB_Write(sensor->slv_addr, VSTRT, vstart >> 2);
    SCCB_Write(sensor->slv_addr, VSTOP, vstart >> 2);
    SCCB_Write(sensor->slv_addr, VREF, ((vstop & 0x03) << 2) | (vstart & 0x03));
}

static int reset(sensor_t *sensor)
{
    int i=0;
    const uint8_t (*regs)[2];

    // Reset all registers
    SCCB_Write(sensor->slv_addr, COM7, 0x80);

    // Delay 10 ms
    systick_sleep(10);

    // Write default regsiters
    for (i=0, regs = default_regs; regs[i][0]; i++) {
        SCCB_Write(sensor->slv_addr, regs[i][0], regs[i][1]);
    }

    // Delay
    systick_sleep(30);

    return 0;
}


static int set_pixformat(sensor_t *sensor, pixformat_t pixformat)
{
    int ret=0;
    // Read register COM7
    uint8_t reg = SCCB_Read(sensor->slv_addr, COM7);

    switch (pixformat) {
        case PIXFORMAT_RGB565:
            reg = reg | 0x04;
            break;
        case PIXFORMAT_YUV422:
        case PIXFORMAT_GRAYSCALE:
            // reg =  COM7_SET_FMT(reg, COM7_FMT_YUV);
            break;
        default:
            return -1;
    }

    // Write back register COM7
    ret = SCCB_Write(sensor->slv_addr, COM7, reg);

    // Delay
    systick_sleep(30);

    return ret;
}

static int set_framesize(sensor_t *sensor, framesize_t framesize)
{
    int ret=0;
    uint8_t reg;

    if (framesize < FRAMESIZE_VGA) {
	pclk_scaling_factor_t sfactor = PCLK_NO_SCALING;

	switch (framesize) {
		case FRAMESIZE_40x30 :
			sfactor = PCLK_SCALING_BY_16;
			break;
		case FRAMESIZE_QQQVGA :
			sfactor = PCLK_SCALING_BY_8;
			break;
		case FRAMESIZE_QQVGA :
			sfactor = PCLK_SCALING_BY_4;
			break;
		case FRAMESIZE_QVGA :
			sfactor = PCLK_SCALING_BY_2;
			break;
		default :
			return -1;
	}
	// Read COM3 reg
	reg = SCCB_Read(sensor->slv_addr, COM3);
	// Set scaling regs
	reg = COM3_SET_SCALE(reg, 1);
	reg = COM3_SET_DCW(reg, 1);
        // Enable auto-scaling/zooming factors
	ret |= SCCB_Write(sensor->slv_addr, COM3, reg);
	
	// Read COM14 reg
	reg = SCCB_Read(sensor->slv_addr, COM14);
	// Set scaling regs
	reg = COM14_SET_PCLK_SCALING(reg, 1);
	reg = COM14_SET_MANUAL_SCALING(reg, 1);
	
	// Enable scaling/zooming factors
	ret |= SCCB_Write(sensor->slv_addr, COM14, reg | sfactor);
	
	reg = SCCB_Read(sensor->slv_addr, SCALING_PCLK_DIV);
	reg = SCALING_PCLK_DIV_BYPASS(reg, 0);
	ret |= SCCB_Write(sensor->slv_addr, SCALING_PCLK_DIV, reg | sfactor);
    } else {
	// Disable scaling/zooming
	reg = SCCB_Read(sensor->slv_addr, COM3);
	reg = COM3_SET_SCALE(reg, 0);
	reg = COM3_SET_DCW(reg, 0);
	ret |= SCCB_Write(sensor->slv_addr, COM3, reg);
	// Disable PCLK and manual scaling control
	reg = SCCB_Read(sensor->slv_addr, COM14);
	reg = COM14_SET_PCLK_SCALING(reg, 0);
	reg = COM14_SET_MANUAL_SCALING(reg, 0);
	ret |= SCCB_Write(sensor->slv_addr, COM14, reg);
        
	reg = SCCB_Read(sensor->slv_addr, SCALING_PCLK_DIV);
	reg = SCALING_PCLK_DIV_BYPASS(reg, 1);
	ret |= SCCB_Write(sensor->slv_addr, SCALING_PCLK_DIV, reg);	

        // Clear auto-scaling/zooming factors
        ret |= SCCB_Write(sensor->slv_addr, SCALING_XSC, 0x00);
        ret |= SCCB_Write(sensor->slv_addr, SCALING_YSC, 0x00);
        ret |= SCCB_Write(sensor->slv_addr, SCALING_DCWCTR, 0x00);
    }

    // Delay
    systick_sleep(30);

    if (ret == 0) {
        sensor->framesize = framesize;
    }

    return ret;
}

static int set_colorbar(sensor_t *sensor, int enable)
{
    int ret=0;
    uint8_t reg;

    test_pattern_t tpattern = enable? TEST_PATTERN_COLOR_BAR : NO_TEST_PATTERN; 

    // Read reg COM7
    reg = SCCB_Read(sensor->slv_addr, COM7);
    // Set color bar
    reg = COM7_SET_COLOR_BAR(reg, enable);
    // Write back COM7
    ret |= SCCB_Write(sensor->slv_addr, COM7, reg);

    // Read reg COM17
    reg = SCCB_Read(sensor->slv_addr, COM17);
    // Set dsp color bar
    reg = COM17_SET_DSP_COLOR_BAR(reg, enable);
    // Write back COM17
    ret |= SCCB_Write(sensor->slv_addr, COM17, reg);

    // Read reg SCALING_XSC
    reg = SCCB_Read(sensor->slv_addr, SCALING_XSC);
    // Write back reg SCALING_XSC
    ret |= SCCB_Write(sensor->slv_addr, SCALING_XSC, reg | SCALING_XSC_SET_TEST_PATTERN(tpattern));
    // Read reg SCALING_YSC
    reg = SCCB_Read(sensor->slv_addr, SCALING_YSC);
    // Write back reg SCALING_YSC
    ret |= SCCB_Write(sensor->slv_addr, SCALING_YSC, reg | SCALING_YSC_SET_TEST_PATTERN(tpattern));

    return ret;
}

static int set_whitebal(sensor_t *sensor, int enable)
{
    // Read register COM8
    uint8_t reg = SCCB_Read(sensor->slv_addr, COM8);
    // Set white bal on/off
    reg = COM8_SET_AWB(reg, enable);
    // Write back register COM8
    return SCCB_Write(sensor->slv_addr, COM8, reg);
}

static int set_gain_ctrl(sensor_t *sensor, int enable)
{
    // Read register COM8
    uint8_t reg = SCCB_Read(sensor->slv_addr, COM8);
    // Set white bal on/off
    reg = COM8_SET_AGC(reg, enable);
    // Write back register COM8
    return SCCB_Write(sensor->slv_addr, COM8, reg);
}

static int set_exposure_ctrl(sensor_t *sensor, int enable)
{
    // Read register COM8
    uint8_t reg = SCCB_Read(sensor->slv_addr, COM8);
    // Set white bal on/off
    reg = COM8_SET_AEC(reg, enable);    
    // Write back register COM8
    return SCCB_Write(sensor->slv_addr, COM8, reg);
}

static int set_hmirror(sensor_t *sensor, int enable)
{
    // Read register COM3
    uint8_t reg = SCCB_Read(sensor->slv_addr, COM3);

    // Set mirror on/off
    reg = MVFP_SET_MIRROR(reg, enable);

    // Write back register COM3
    return SCCB_Write(sensor->slv_addr, COM3, reg);
}

static int set_vflip(sensor_t *sensor, int enable)
{
    // Read register COM3
    uint8_t reg = SCCB_Read(sensor->slv_addr, COM3);

    // Set mirror on/off
    reg = MVFP_SET_VFLIP(reg, enable);

    // Write back register COM3
    return SCCB_Write(sensor->slv_addr, COM3, reg);
}

int ov7670_init(sensor_t *sensor)
{
    // Set function pointers
    sensor->reset = reset;
    sensor->set_pixformat = set_pixformat;
    sensor->set_framesize = set_framesize;
    sensor->set_colorbar = set_colorbar;
    sensor->set_whitebal = set_whitebal;
    sensor->set_gain_ctrl = set_gain_ctrl;
    sensor->set_exposure_ctrl = set_exposure_ctrl;
    sensor->set_hmirror = set_hmirror;
    sensor->set_vflip = set_vflip;

    // Retrieve sensor's signature
    sensor->id.MIDH = SCCB_Read(sensor->slv_addr, REG_MIDH);
    sensor->id.MIDL = SCCB_Read(sensor->slv_addr, REG_MIDL);
    sensor->id.PID = SCCB_Read(sensor->slv_addr, REG_PID);
    sensor->id.VER = SCCB_Read(sensor->slv_addr, REG_VER);

    // Set sensor flags
    SENSOR_HW_FLAGS_SET(sensor, SENSOR_HW_FLAGS_VSYNC, 0);
    SENSOR_HW_FLAGS_SET(sensor, SENSOR_HW_FLAGS_HSYNC, 0);
    SENSOR_HW_FLAGS_SET(sensor, SENSOR_HW_FLAGS_PIXCK, 1);
    SENSOR_HW_FLAGS_SET(sensor, SENSOR_HW_FLAGS_FSYNC, 1);
    SENSOR_HW_FLAGS_SET(sensor, SENSOR_HW_FLAGS_JPEGE, 0);

    //frame_control(sensor, 196, 52, 8, 232);

    return 0;
}
