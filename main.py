import pygame
pygame.init()

screen = pygame.display.set_mode([640, 360], pygame.FULLSCREEN)

def main():
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return

        screen.fill((255, 255, 255))

        pygame.draw.circle(screen, (0, 0, 255), (250, 250), 75)

        pygame.display.flip()
        print(screen.get_size())


if __name__ == "__main__":
    main()
    pygame.quit()
