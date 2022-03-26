#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./mfaGrass.xpm";
	char	*relative_path_water = "./mfaWater.xpm";
	int		img_width = 60;
	int		img_height = 60;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 300, "so_long");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img = mlx_xpm_file_to_image(mlx, relative_path_water, &img_width,
								&img_height);
	// img_width img_height ни на что не влияют ХЗ почему так
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	//mlx_hook(mlx_win, 17, 0, ft_close, 0); // TODO ft_close, это чтобы
	// программа останавливалвсь прои нажатии на крестик в окне
	mlx_loop(mlx);
}

//typedef struct	s_data {
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}				t_data;
//
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}
//
//int	main(void)
//{
//	void	*mlx;
//	void	*mlx_win;
//	t_data	img;
//
//	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 600, 300, "Hello world!");
//	img.img = mlx_new_image(mlx, 600, 300);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								 &img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_loop(mlx);
//}
