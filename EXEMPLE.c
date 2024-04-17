#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

#define WIDTH 500
#define HEIGHT 500

// static mlx_image_t* image;

// -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8  | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // // -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// #include <stdlib.h>
// #include <stdio.h>
// #include <stdio.h>
// // #include "MLX42/MLX42.h"
// // #define WIDTH 720
// // #define HEIGHT 480

// // void my_keyhook(mlx_key_data_t keydata, void* param)
// // {
// // 	(void) param;
// // 	// If we PRESS the 'J' key, print "Hello".
// // 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// // 		puts("Hello ");

// // 	// If we RELEASE the 'K' key, print "World".
// // 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// // 		puts("World");

// // 	// If we HOLD the 'L' key, print "!".
// // 	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
// // 		puts("!");
// // }

// // int32_t	main(void)
// // {
// // 	mlx_t* mlx;

// // 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// // 		return (EXIT_FAILURE);

// // 	mlx_key_hook(mlx, &my_keyhook, NULL);
// // 	mlx_loop(mlx);
// // 	mlx_terminate(mlx);
// // 	return (EXIT_SUCCESS);
// // }
// #include <stdlib.h>
// #include <stdio.h>
// #include <stdio.h>
// // #include "MLX42/MLX42.h"
// #define WIDTH 720
// #define HEIGHT 480

// void my_scrollhook(double xdelta, double ydelta, void* param)
// {
// 		(void) param;
// 	// Simple up or down detection.
// 	if (ydelta > 0)
// 		puts("Up!");
// 	else if (ydelta < 0)
// 		puts("Down!");
	
// 	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
// 	if (xdelta < 0)
// 		puts("Sliiiide to the left!");
// 	else if (xdelta > 0)
// 		puts("Sliiiide to the right!");
// }

// int32_t	main(void)
// {
// 	mlx_t* mlx;

// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 		return (EXIT_FAILURE);

// 	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
// #include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
// #define WIDTH 256
// #define HEIGHT 256

static mlx_image_t	*g_img;

void	hook(void* param)
{
	mlx_t* mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_P))
		mlx_delete_image(mlx, g_img);
	for (int x = 0; x < (int)g_img->width; x++)
		for(int y= 0; y < (int)g_img->height; y++)
			mlx_put_pixel(g_img, x, y, rand() % RAND_MAX);
}

int32_t	main(void)
{
	mlx_t*    mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	// g_img = mlx_new_image(mlx, 128, 128);
	// mlx_image_to_window(mlx, g_img, 0, 0);
	// mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include "MLX42/MLX42.h"
// #define WIDTH 256
// #define HEIGHT 256

// // Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();

// 	/* Do stuff */

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();

// 	// Even after the image is being displayed, we can still modify the buffer.
// 	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }