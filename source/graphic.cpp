
#include "graphic.h"

void pp2d_draw_texture_scale_blend(size_t id, int x, int y, float scaleX, float scaleY, u32 color)
{
	pp2d_texture_select(id, x, y);
	pp2d_texture_blend(color);
	pp2d_texture_scale(scaleX, scaleY);
	pp2d_texture_draw();		
}

void pp2d_draw_texture_part_blend(size_t id, int x, int y, int xbegin, int ybegin, int width, int height, u32 color)
{
	pp2d_texture_select_part(id, x, y, xbegin, ybegin, width, height);
	pp2d_texture_blend(color);
	pp2d_texture_draw();		
}

void pp2d_draw_texture_part_scale(size_t id, int x, int y, int xbegin, int ybegin, int width, int height, float scaleX, float scaleY)
{
	pp2d_texture_select_part(id, x, y, xbegin, ybegin, width, height);
	pp2d_texture_scale(scaleX, scaleY);
	pp2d_texture_draw();
}

void pp2d_draw_texture_part_scale_blend(size_t id, int x, int y, int xbegin, int ybegin, int width, int height, float scaleX, float scaleY, u32 color)
{
	pp2d_texture_select_part(id, x, y, xbegin, ybegin, width, height);
	pp2d_texture_blend(color);
	pp2d_texture_scale(scaleX, scaleY);
	pp2d_texture_draw();		
}

void pp2d_draw_texture_rotate_flip_blend(size_t id, int x, int y, float angle, flipType fliptype, u32 color)
{
	pp2d_texture_select(id, x, y);
	pp2d_texture_rotate(angle);
	pp2d_texture_flip(fliptype);
	pp2d_texture_blend(color);
	pp2d_texture_draw();
}

//void pp2d_free_texture(size_t id)
//{
//	if (id >= MAX_TEXTURES)
//		return;
//	
//	if (!textures[id].allocated)
//		return;
//	
//	C3D_TexDelete(&textures[id].tex);
//	textures[id].width = 0;
//	textures[id].height = 0;
//	textures[id].allocated = false;
//}

size_t loadingbgtex = 1;
size_t topbgtex = 2;
size_t subbgtex = 3;
size_t buttontex = 4;
size_t extrasmallbuttontex = 5;
size_t smallbuttontex = 6;
size_t dot = 7;
size_t pageframe = 8;
size_t mainmenutoptex = 9;
size_t mainmenubottomtex = 10;
size_t pksmbottomtex = 11;
size_t pksmtoptex = 12;

void graphicsInit(void) {
}