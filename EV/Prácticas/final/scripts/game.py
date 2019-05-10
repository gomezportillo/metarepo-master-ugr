import bge

def menu(controller):
	controller = bge.logic.getCurrentController()
	scene = bge.logic.getCurrentScene()

	up     = controller.sensors['Up']
	down   = controller.sensors['Down']
	select = controller.sensors['Select']

	sound = controller.actuators['Sound']

	spaceship = controller.owner
	start_y_position = 0
	exit_y_position  = -2

	if down.positive and spaceship.worldPosition.y == start_y_position:
		spaceship.worldPosition.y -= 2
		controller.activate(sound)

	if up.positive and spaceship.worldPosition.y == exit_y_position:
		spaceship.worldPosition.y += 2
		controller.activate(sound)

	if select.positive:
		if spaceship.worldPosition.y == start_y_position:
			scene.replace('Game')

		if spaceship.worldPosition.y == exit_y_position:
			bge.logic.endGame()
